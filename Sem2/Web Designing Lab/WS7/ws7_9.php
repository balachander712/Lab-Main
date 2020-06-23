<?php


    if(!isset($_SESSION['name']))
    {
        if(isset($_GET['name']))
        {
            $_SESSION['name'] = $_GET['name'];
        }

    }
    
?>

<!DOCTYPE HTML>
<HTML>
	<head>
		<title>
			ws7_9
		</title>
	</head>
	<body>
        <h1>Enter your name</h1>
        <form>
            <input type = "text" name = "name" ><br><br>
            <input type="submit">
        </form>
        <?php
            if(isset($_SESSION['name']))
            {
                echo "<br><h3>Hello {$_SESSION['name']}</h3>";
            }
        ?>
	</body>
</html>
