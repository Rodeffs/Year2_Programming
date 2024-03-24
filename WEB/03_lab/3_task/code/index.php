<!DOCTYPE html>

<html lang="en">
	<head>
		<title>Working with files (painfully)</title>
	</head>
	<body>
		<div id="submission">
			<h1>Enter submission</h1>
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
			<table>
				<thead>
					<th>Category</th>
					<th>Email</th>
					<th>Title</th>
					<th>Content</th>	
				</thead>
				<tbody>
					<?php
						function output($filePath, $toOutput) { // рекурсивное считывание
							$directories = array_slice(scandir($filePath), 2);

							foreach ($directories as $dir) {
								$nextFilePath = $filePath."/{$dir}";
								
								if (mime_content_type($nextFilePath) == "text/plain") { // проверка на текстовый файл
									$title = substr($dir, 0, -4); // чтобы убрать .txt с конца
									$text = nl2br(file_get_contents($nextFilePath)); // nl2br нужно, чтобы правильно отображать \n

									echo "{$toOutput}<td>{$title}</td><td>{$text}</td></tr>";
								}
								else {
									output($nextFilePath, $toOutput."<td>{$dir}</td>");
								}	
							}
						}
						
						if (is_dir("categories")) {
							output("categories", "<tr>");
						}
					?>
				</tbody>	
			</table>
		</div>
	</body>
</html>
