<?php

include('lock.php');

?>

<html>

<script type="text/javascript">
function changetextbox()
{
	if (document.getElementById("mfi_4_a_i").value == "Yes") 
	{
	   document.getElementById('upload_form').innerHTML = '<form action="upload.php" method="post" enctype="multipart/form-data">Select video to upload:<br><input type="file" name="fileToUpload" id="fileToUpload"><br><input type="submit" value="Upload Video" name="submit"><br></form>'
    } 
	else 
	{
		document.getElementById('upload_form').innerHTML = ''
    }
}
</script>

<body>
<br><a href="login.php">Login</a>  |  <a href="logout.php">Logout</a> | <a href="upload.php">Upload Video</a> | <a href="videos.php">Videos</a></br>
<br></br>

<?php


if (isset($_POST['submit']))
{
    $file_name = $_FILES['fileToUpload']['name'];
    $file_type = $_FILES['fileToUpload']['type'];
    $file_size = $_FILES['fileToUpload']['size'];

    $allowed_extensions = array("webm", "mp4", "ogv", "mpg", "mov");
    $file_size_max = 2147483648;
    $pattern = implode ($allowed_extensions, "|");


    echo $file_name;
    echo "<br>";
    echo $file_type;
    echo "<br>";
    echo $file_size;
    echo "<br>";

    

    if (!empty($file_name))
    {    //here is what I changed - as you can see above, I used implode for the array
        // and I am using it in the preg_match. You pro can do the same with file_type,
        // but I will leave that up to you
        if (preg_match("/({$pattern})$/i", $file_name) && $file_size < $file_size_max)
        {
            if (($file_type == "video/webm") || ($file_type == "video/mp4") || ($file_type == "video/ogv") || ($file_type == "video/mpeg") || ($file_type == "video/quicktime") )
            {
                if ($_FILES['fileToUpload']['error'] > 0)
                {
                    echo "Unexpected error occured, please try again later.";
                } else {
						$date = date_create();
						$new_filename = date_timestamp_get($date)."_".$file_name;
                    if (file_exists("secure/".$new_filename))
                    {
                        echo $file_name." already exists.";
                    } else {
                        move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], "secure/".$new_filename);
                        echo "Stored in: " . "secure/".$new_filename;
						/*** convert video to flash ***/
						/*exec("avconv -i secure/{$file_name} -c:v libx264 secure/{$file_name}.mp4");*/
						exec("ffmpeg -i secure/{$new_filename} -ar 22050 -ab 32 -f flv -s 320x240 secure/{$new_filename}.flv");
						exec("ffmpeg -y -i secure/{$new_filename} -vcodec: libtheora -qscale:v 7 -acodec libvorbis -qscale:a 5  secure/{$new_filename}.ogv");
						exec("ffmpeg -i secure/{$new_filename} -vcodec: libx264  -s 320x240 secure/{$new_filename}.mp4");
						
						?>
						<br>
						<video controls>;
						<source src="secure/<? echo $new_filename?>.mp4" type="video/mp4">;
						<source src="secure/<? echo $new_filename?>.ogg" type="video/ogg">";
						"Your browser does not support the video tag."
						</video>
						<?
                    }
                }
            } else {
                echo "Invalid video format.";
            }
        }else{
            echo "where is my mojo?? grrr";
        }
    } else {
        echo "Please select a valid video to upload.";
    }
}
else
{
?>
	Would you like to upload a new file?
	<select id="mfi_4_a_i" name="mfi_4_a_i" onChange="changetextbox();">
		<option>No</option>
		<option>Yes</option>
	</select>
	<br>
	<p id="upload_form"></p>
<? 

}
?>
</body>
</html>
