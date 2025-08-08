<!doctype html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport"
        content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Upload file with Progress Bar</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</head>

<body>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col col-md-6 card mt-5 p-3">
                <h3 class="text-center">Upload File with Progress Bar</h3>
                <form id="uploadForm">
                    <div class="form-group">
                        <label for="name">File Name</label>
                        <input name="fileName" id="name" type="text" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <div class="custom-file">
                            <input name="myFile" type="file" class="custom-file-input" id="myFile" required>
                            <label class="custom-file-label" for="myFile">Choose file</label>
                        </div>
                    </div>
                    <div class="form-group">
                        <button type="submit" class="btn btn-primary">Upload</button>
                    </div>
                </form>
                <div class="progress mt-3" style="height: 25px; display: none;">
                    <div class="progress-bar progress-bar-striped progress-bar-animated" role="progressbar"
                        style="width: 0%;" id="progressBar">0%</div>
                </div>
                <div id="uploadStatus" class="mt-3"></div>
            </div>
        </div>
    </div>

    <script>
        $(document).ready(function () {
    $('#uploadForm').on('submit', function (e) {
        e.preventDefault(); // Prevent default form submission

        const formData = new FormData(this);
        const progressBar = $('#progressBar');
        const progressContainer = $('.progress');
        const uploadStatus = $('#uploadStatus');

        // Reset progress bar and status
        progressBar.css('width', '0%').text('0%');
        progressContainer.show();
        uploadStatus.html('');

        $.ajax({
            url: 'upload.php', // Server-side script to handle the upload
            type: 'POST',
            data: formData,
            contentType: false,
            processData: false,
            xhr: function () {
                const xhr = new window.XMLHttpRequest();
                xhr.upload.addEventListener('progress', function (e) {
                    if (e.lengthComputable) {
                        const percentComplete = Math.round((e.loaded / e.total) * 100);
                        progressBar.css('width', percentComplete + '%').text(percentComplete + '%');
                    }
                }, false);
                return xhr;
            },
            success: function (response) {
                progressBar.css('width', '100%').text('100%');
                uploadStatus.html('<div class="alert alert-success">File uploaded successfully!</div>');
            },
            error: function () {
                progressBar.css('width', '0%').text('0%');
                uploadStatus.html('<div class="alert alert-danger">File upload failed. Please try again.</div>');
            }
        });
    });

    // Update the file input label with the selected file name
    $(".custom-file-input").on("change", function () {
        const fileName = $(this).val().split("\\").pop();
        $(this).siblings(".custom-file-label").addClass("selected").html(fileName);
    });
});
    </script>
</body>

</html>