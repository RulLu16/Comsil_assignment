<?php
	$fp=fopen("counter.txt", "r");
	$count=fread($fp,filesize("counter.txt"));
	if ($_COOKIE == NULL) {
		setcookie("ip", 1);
		$count++;
	}// 쿠키가 있는지 없는지를 판별하여 없으면 방문자수를 하나 늘리고 쿠키를 지급해준다.
?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<?php
	echo("Number of visitant : ");
	$st=(string)$count; //한자리씩 출력해야 하므로 숫자를 문자열로 바꾼다
	for($i=0;$i<strlen($st);$i++)
	{
		$num=substr($st,$i,1); //문자 한자리씩 num에 넣어준다
		switch ($num) {
			case '0': echo("<img src=\"zero.jpg\">");
			break;
			case '1': echo("<img src=\"one.jpg\">");
			break;
			case '2': echo("<img src=\"two.jpg\">");
			break;
			case '3': echo("<img src=\"three.jpg\">");
			break;
			case '4': echo("<img src=\"four.jpg\">");
			break;
			case '5': echo("<img src=\"five.jpg\">");
			break;
			case '6': echo("<img src=\"six.jpg\">");
			break;
			case '7': echo("<img src=\"seven.jpg\">");
			break;
			case '8': echo("<img src=\"eight.jpg\">");
			break;
			case '9': echo("<img src=\"nine.jpg\">");
			break;

		} //경우에 따라 숫자를 출력한다.
	}
	fclose($fp);
	$fp=fopen("counter.txt","w");
	fwrite($fp, "$count", strlen($count));
	fclose($fp);
	?>
</body>
</html>