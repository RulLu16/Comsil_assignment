<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title></title>
</head>
<body>
	<?php
		echo("<b>게시판 쓰기</b><br><br>");
		echo("<form action = \"board_main.php\" accept-charset=\"utf-8\" name = \"board_info\" method = \"POST\">
                    <textarea name = \"comment\" cols = \"50\" rows = \"10\"></textarea>
                    <br><br>
                    <input type = \"submit\" value = \"등록하기\"/>
                    <input type = \"reset\" value = \"다시기입\"/><br><br>
        </form>"); //textarea에서 받은 내용을 form 태그를 이용하여 board_main.php로 넘긴다. input태그의 submit, reset 타입을 이용하여 등록일 경우 쓴 내용을 board_main.php에 넘기고 다시기입일 경우 textarea에 있는 내용을 지운다.
		echo("<br><a href=\"board_main.php\">되돌아가기</a>");
	?>

</body>
</html>