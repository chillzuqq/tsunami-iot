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

            # Ensure that all data is read before executing another query
            cursor.fetchall()  # This will clear any remaining results
            cursor.close()  # Close the first cursor

            msgcursor = connection.cursor()
            show_msg = "SELECT * FROM warn_msg"
            msgcursor.execute(show_msg)
            msg = msgcursor.fetchall()
            msgcursor.close()  # Close the second cursor
            
            phonecursor = connection.cursor()
            show_phone = "SELECT * FROM nomor_penerima"
            phonecursor.execute(show_phone)
            phone = phonecursor.fetchall()
            phonecursor.close()  # Close the second cursor

            for i in phone:
                if results is None:
                    print("No data found.")
                else:
                    # Check results and print appropriate messages
                    if results[0] == 0 and results[1] == 0:
                        print("All clear.")
                    elif results[0] == 1 and results[1] == 0:
                        print(msg[0][1])
                        testwa.sendMSG(i[1], msg[0][1])
                    elif results[0] == 0 and results[1] == 1:
                        print(msg[1][1])
                        testwa.sendMSG(i[1], msg[1][1])
                    elif results[0] == 1 and results[1] == 1:
                        print(msg[2][1])
                        testwa.sendMSG(i[1], msg[2][1])

        except Error as e:
            print(f"Error during database operation: {e}")

        finally:
            # Ensure the connection is closed
            close_connection(connection)

        # Sleep for a defined interval before the next iteration
        time.sleep(1)

if __name__ == "__main__":
    main_loop()
