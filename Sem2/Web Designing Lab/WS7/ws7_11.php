<?php
        if(isset($_GET['name']))
        {
            setcookie("cookie",$_GET['name']);
        }
?>

<!DOCTYPE HTML>
<HTML>
	<head>
		<title>
			ws7_11
		</title>
	</head>
	<body>


        <h1>Enter your name<h1>
        <p>Reload</p>
        <form>
            <input type = "text" name = "name" ><br><br>
            <input type="submit" value="Enter!!">
        </form>
        <?php
        if(isset($_GET['name']))
        {
            echo "Cookie is {$_COOKIE['cookie']}";
        }
        ?>
	</body>
</html>
