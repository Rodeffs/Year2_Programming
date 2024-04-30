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

$id = "1Pjne_2pugD5LtMJOuF5weDIwgOmH48m6N3tbqd0BaXI";
$name = "lab4 table";
$table = [[$category, $email, $title, $content]];

$body = new Google_Service_Sheets_ValueRange(['values' => $table]);
$params = array('valueInputOption' => 'USER_ENTERED');  

$service->spreadsheets_values->append($id, $name, $body, $params);

goBack();

?>
