<!DOCTYPE html>

<html lang="en">
	<head>
		<title>Who needs phpstorm when you have VIM!!!1!!</title>
	</head>
	<body>
		<div id="step 1">
			<h1>Step 1</h1>
			<?php include "step1.php"; ?>
			<form method="post" action="step1.php">
				<textarea id="text1" name="text1" rows="20" cols="120"></textarea>
				<input type="submit" name="submit text" value="COUNT" >
			</form>
			<?php
			if (isset($_COOKIE["word_count"])) {	
				echo "Word count is {$_COOKIE["word_count"]};\n";
			}
			if (isset($_COOKIE["char_count"])) {	
				echo "Character count is {$_COOKIE["char_count"]}\n";
			}
			?>
		</div>
		<div id="step 2 & 3">
			<h1>Step 2 & 3</h1>
			<?php include "step2-3.php"; ?>
			<form method="post" action="step2-3.php">
				<label for="surname">Surname</label>
				<input type="surname" name="surname">

				<label for="name">Name</label>
				<input type="name" name="name">

				<label for="age">Age</label>
				<input type="age" name="age">

				<label for="salary">Salary</label>
				<input type="salary" name="salary">

				<label for="email">Email</label>
				<input type="email" name="email">
			</form>
		</div>
	</body>
</html>
