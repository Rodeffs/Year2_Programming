<?php
require_once "vendor/autoload.php";

function goBack() {
	header("Location: /");
	exit();
}

if (false === isset($_POST["email"], $_POST["category"], $_POST["title"], $_POST["content"]))  {
	goBack();
}

$email = $_POST["email"];
$category = $_POST["category"];
$title = $_POST["title"];
$content = $_POST["content"];

$client = new Google_client();
$client->setAuthConfig("credentials.json");
$client->addScope('https://www.googleapis.com/auth/spreadsheets');
$service = new Google_Service_Sheets($client);

$id = "lab4-web-421921";
$name = "Table";
$table = [[$category, $email, $title, $content]];

$body = new Google_Service_Sheets_ValueRange(['values' => $table]);
$params = array('valueInputOption' => 'USER_ENTERED');  

$service->spreadsheets_values->append($id, $name, $body, $params);

goBack();

?>
