<?php
    session_start();
    if(isset($_SESSION['name']))
    {
        
        $_SESSION['name'] .= " " . $_GET['name'];
    }
    else
    {
        if(isset($_GET['name']))
        {
            $_SESSION['name'] =  $_GET['name'];
        }
    }
?>

<!DOCTYPE HTML>
<HTML>
	<head>
		<title>
			ws7_10
		</title>
	</head>
	<body>


        <h1>Enter your our item</h1>
        <form>
            <input type = "text" name = "name" ><br><br>
            <input type="submit" value="Add Item">
        </form>
        <?php
            if(isset($_SESSION['name']))
            {
                echo "<br><h3>Your Cart items<br> {$_SESSION['name']}</h3>";
            }
        ?>
	</body>
</html>
