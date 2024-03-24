<!DOCTYPE html>

<html lang="en">
	<head>
		<title>Working with files</title>
	</head>
	<body>
		<div id="submission">
			<h1>Submit broadcast</h1>
			<form method="post" action="submit.php">
				<label for="email">Email</label>
				<input type="email" name="email" required><br>

				<label for="category">Category</label>
				<select name="category" required>
					<option value="business">Business</option>
					<option value="education">Education</option>
					<option value="finances">Finances</option>
					<option value="family">Family</option>
					<option value="other">Other</option>
				</select><br>

				<label for="title">Title</label>
				<input type="title" name="title" required><br>

				<label for="content">Content</label>
				<textarea id="content" name="content" rows="20" cols="120" required></textarea><br>

				<input type="submit" name="submit_broadcast" value="SUBMIT" >
			</form>
		</div>
		<div id="table">
			<h3>Uploaded submissions:</h3>
		</div>
	</body>
</html>
