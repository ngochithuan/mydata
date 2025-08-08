<?php 
session_start();

if (empty($_POST['fileName']) || empty($_FILES['myFile']['name'])) {
    $_SESSION['error'] = "Please provide a valid file name and select a file to upload.";
    header("Location: exercise1.php?error=emptyFields");
    die();
}

$savedName = $_POST['fileName'];
$file = $_FILES['myFile'];

$name = $file['name'];
$type = $file['type'];
$tmpName = $file['tmp_name'];
$error = $file['error'];
$size = $file['size'];

if ($error !== UPLOAD_ERR_OK) {
    $_SESSION['error'] = "An error occurred during file upload. Error code: $error";
    header("Location: exercise1.php?error=fileUploadError");
    die();
}

$ext = strtolower(pathinfo($name, PATHINFO_EXTENSION));

$supportedTypes = array('txt', 'doc', 'docx', 'xls', 'xlsx', 'jpg', 'png', 'mp3', 'mp4', 'pdf', 'rar', 'zip');
if (!in_array($ext, $supportedTypes)) {
    $_SESSION['error'] = "This file type is not allowed. Please upload a valid file.";
    header("Location: exercise1.php?error=unsupportedFileType");
    die();
}

$maxSize = 500 * 1024 * 1024; 
if ($size > $maxSize) {
    $_SESSION['error'] = "File exceeds the maximum allowed size of 500MB.";
    header("Location: exercise1.php?error=fileSizeExceeded");
    die();
}

$root = $_SERVER['DOCUMENT_ROOT'];
$final_path = $root . '/uploads/' . $savedName . '.' . $ext;

if (!is_dir(dirname($final_path))) {
    mkdir(dirname($final_path), 0777, true); 
}

if (file_exists($final_path)) {
    $_SESSION['error'] = "This file already exists. Please choose a different name.";
    header("Location: exercise1.php?error=fileExists");
    die();
}

if (!move_uploaded_file($tmpName, $final_path)) {
    $_SESSION['error'] = "Failed to save the uploaded file.";
    header("Location: exercise1.php?error=fileSaveError");
    die();
}

$_SESSION['success'] = "File uploaded successfully!";
header("Location: exercise1.php?success=fileUploaded");
die();