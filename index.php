<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "testiot";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

if ($_GET['trig1'] != NULL) {
    $sql1 = "DELETE FROM temptrig1";
    $conn->query($sql1);
    $trig1 = $_GET['trig1'];
    $sql = "INSERT INTO temptrig1 (trig1)
    VALUES ($trig1)";
    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
} else if ($_GET['trig2'] != NULL) {
    $sql1 = "DELETE FROM temptrig2";
    $conn->query($sql1);
    $trig2 = $_GET['trig2'];
    $sql = "INSERT INTO temptrig2 (trig2)
    VALUES ($trig2)";
    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
