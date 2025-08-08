<?php
$countries = ["Vietnam", "Venezuela", "Vatican City", "United States", "United Kingdom", "Ukraine", "Uganda", "Uruguay", "Uzbekistan", "United Arab Emirates", "India", "Indonesia", "Iceland", "Ireland", "Italy", "Iran", "Iraq"];

$query = isset($_POST['query']) ? strtolower(trim($_POST['query'])) : '';

$result = [];

if ($query !== '') {
    foreach ($countries as $country) {
        if (stripos($country, $query) !== false) {
            $result[] = $country;
        }
    }
}

header('Content-Type: application/json');
echo json_encode($result);
?>
