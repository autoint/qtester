<?php
define('DB_SERVER', 'mysql.qtester.orinsw.com');
define('DB_USERNAME', 'ncr_test');
define('DB_PASSWORD', 'test1234');
define('DB_DATABASE', 'qtester_app');
$db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE);
?>