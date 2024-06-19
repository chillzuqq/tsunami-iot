import mysql.connector as mysql
from mysql.connector import Error
import time
import testwa

def create_connection():
    """Create a new database connection."""
    try:
        connection = mysql.connect(
            host='localhost',
            user='root',
            password='',
            database='testiot'
        )
        if connection.is_connected():
            # print("Connected to the database")
            return connection
    except Error as e:
        print(f"Error connecting to database: {e}")
        return None

def close_connection(connection):
    """Close the database connection."""
    if connection and connection.is_connected():
        connection.close()
        # print("Connection closed")

def main_loop():
    """Main loop where the database operations are performed."""
    while True:
        connection = create_connection()
        if connection is None:
            # Wait before retrying if connection fails
            time.sleep(5)
            continue

        try:
            cursor = connection.cursor()
            show_data = "SELECT * FROM tempsensors"
            cursor.execute(show_data)

            results = cursor.fetchone()
            if results is None:
                print("No data found.")
            else:
                # Check results and print appropriate messages
                if results[0] == 0 and results[1] == 0:
                    print("All clear.")
                elif results[0] == 1 and results[1] == 0:
                    print("Early warning")
                    testwa.sendMSG("+6281319362661", "Early Warning")
                elif results[0] == 0 and results[1] == 1:
                    print("Warning")
                elif results[0] == 1 and results[1] == 1:
                    print("Run to high place immediately")

        except Error as e:
            print(f"Error during database operation: {e}")

        finally:
            # Ensure the cursor and connection are closed
            if cursor:
                cursor.close()
            close_connection(connection)

        # Sleep for a defined interval before the next iteration
        time.sleep(1)

if __name__ == "__main__":
    main_loop()
