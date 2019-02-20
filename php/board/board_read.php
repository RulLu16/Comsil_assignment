<html>
	<head>
		<meta charset="utf-8">
	</head>
	<body>
		<?php

			echo("<b>게시판 읽기</b><br><br>");
			$fp=fopen("data.txt","r");
			$text=fread($fp, filesize("data.txt")); //data.txt의 내용을 복사
			echo("<table border=1 height=40% width=400>
				<tr><td>"); //data.txt 내용을 보여줄 표 생성
			echo($text);
			echo("</td></tr></table>");
			echo("<br><br><a href=\"board_main.php\">되돌아가기</a>");
		?>
	</body>
</html>