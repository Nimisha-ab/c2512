import logging
import json
from chromadb.utils import embedding_functions
import ollama
import chromadb

# Initialize logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Initialize Chroma client
client = chromadb.Client()

# Initialize embedding function using Ollama (as per your setup)
# embedding_function = embedding_functions.OllamaEmbeddingFunction(model="llama-model")

# Create or connect to a Chroma collection
collection = client.get_or_create_collection(name="my_collection")

# Function to embed and store data in ChromaDB
def store_data_in_vector_db(data):
    try:
        # Embed the data
        # embeddings = embedding_function.embed(data)
        
        # Store the embeddings in the ChromaDB
        collection.add(
            # embeddings=embeddings,
            documents=[data],
            metadatas=[{"source": "example_source"}],  # Optional metadata
            ids=[str(hash(data))]  # Unique ID for the document
        )

        logger.info("Data successfully stored in the vector database.")
        return json.dumps({"message": "Data successfully stored!"})

    except Exception as e:
        logger.error(f"Error storing data in ChromaDB: {e}")
        return json.dumps({"error": f"Error storing data: {e}"})

# Function to retrieve data from the vector DB based on a query
def retrieve_data_from_vector_db(query):
    try:
        # Embed the query
        query_embedding = embedding_function.embed(query)

        # Retrieve similar documents based on query embedding
        results = collection.query(
            query_embeddings=[query_embedding],
            n_results=5  # Number of results to retrieve
        )

        logger.info(f"Retrieved {len(results['documents'])} results from the vector database.")
        return json.dumps({"message": "Data retrieval successful!", "results": results['documents']})

    except Exception as e:
        logger.error(f"Error retrieving data from ChromaDB: {e}")
        return json.dumps({"error": f"Error retrieving data: {e}"})

# Function to generate a response based on the retrieved data
def generate_response(query):
    try:
        # Call Llama model to generate a response
        # response = ollama.chat(model="llmama3.2:1b:", messages=[{"role": "user", "content": query}])
        response = "this is the response"
        
        # Return the generated response
        logger.info("Response generated successfully.")
        # return json.dumps({"message": "Response generated!", "response": response['text']})
        return json.dumps({"message": "Response generated!", "response": response})

    except Exception as e:
        logger.error(f"Error generating response: {e}")
        return json.dumps({"error": f"Error generating response: {e}"})

# Example usage
if __name__ == "__main__":
    # Example data and query
    data = "This is an example document to be stored."
    query = "What is an example document?"

    # Store data
    print(store_data_in_vector_db(data))

    # Retrieve data
    print(retrieve_data_from_vector_db(query))

    # Generate response
    print(generate_response(query))
