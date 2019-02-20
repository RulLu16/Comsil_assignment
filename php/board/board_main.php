<html>
	<head>
		<meta charset="utf-8"> <!--한글을 사용하게 해준다 -->
		<title></title>
	</head>
	<body>
		<?php
			echo("<a href=\"board_write.php\">게시판 쓰기</a><br>");
			echo("<a href=\"board_read.php\">게시판 읽기</a><br>");
			if(htmlspecialchars($_POST['comment'])!=NULL) //write에서 받은 textarea값이 있는지 확인
			{
				$fp=fopen("data.txt","w");
				$text=htmlspecialchars($_POST['comment']);
				fwrite($fp, $text); //data.txt를 갱신
				fclose($fp);

			}
		?>
	</body>
</html>