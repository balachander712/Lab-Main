<?php
        $isValid = "false";
        if(isset($_POST['user']))
        {
            $conn= mysqli_connect("localhost", "root", "root", "mydb");
            if (!$conn)
            {
                echo "Error: " . mysqli_connect_error();
            }
            else
            {
                $sql = "SELECT * FROM userdetails";
                $retval = mysqli_query($conn,$sql);
                $row;
                while ($row = mysqli_fetch_assoc($retval))
                {
                    if ($_POST['user'] == $row['username'] && ($_POST['password'] == $row['password']))
                    {
                        $isValid = "true";
                    }
                }
            }
        }
?>

<!DOCTYPE HTML>
<HTML>
	<head>
		<title>
			ws7_16
		</title>
	</head>
	<body>
        <h1>Verification process</h1>
        <form method="post">
            <h3>Enter the User Id</h3>
            <input type = "text" name = "user" placeholder="Enter the user-id ">
            <h3>Enter the Password</h3>
            <input type = "password" name = "password" placeholder="Enter the password "><br><br>
            <input type="submit">
        </form>
        <?php
            if(isset($_POST['user']))
            {
                if ($isValid == "true") {
                    echo "<P>Username and Password are validated and the given cred is CORRECT</P>";
                }
                else {
                    echo "<p>Username and Password are validated and the given cred is INCORRECT</p>";
                }
            }
            ?>
	</body>
</html>
