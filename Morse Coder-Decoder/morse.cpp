#include "stdafx.h"
#include "morse.h"

const char *toMorse(wchar_t c)
{
	static char *english[26] = 
	{
		".-",		//A
		"-...",		//B
		"-.-.",		//C
		"-..",		//D
		".",		//E
		"..-.",		//F
		"--.",		//G
		"....",		//H
		"..",		//I
		".---",		//J
		"-.-",		//K
		".-..",		//L
		"--",		//M
		"-.",		//N
		"---",		//O
		".--.",		//P
		"--.-",		//Q
		".-.",		//R
		"...",		//S
		"-",		//T
		"..-",		//U
		"...-",		//V
		".--",		//W
		"-..-",		//X
		"-.--",		//Y
		"--.."		//Z
	};
	static char *number[10] = 
	{
		"-----",	//0
		".----",	//1
		"..---",	//2
		"...--",	//3
		"....-",	//4
		".....",	//5
		"-....",	//6
		"--...",	//7
		"---..",	//8
		"----."		//9
	};
	static char *Greek[25] = 
	{
		".-",		//á
		"-...",		//â
		"--.",		//ã
		"-..",		//ä
		".",		//å
		"--..",		//æ
		"....",		//ç
		"-.-.",		//è
		"..",		//é
		"-.-",		//ê
		".-..",		//ë
		"--",		//ì
		"-.",		//í
		"-..-",		//î
		"---",		//ï
		".--.",		//ð
		".-.",		//ñ
		"...",		//ó
		"...",		//ò
		"-",		//ô
		"-.--",		//õ
		"..-.",		//ö
		"----",		//÷
		"--.-",		//ø
		".--",		//ù
	};
	static char *restGreek1[] = 
	{
		".-",		//¢
		"",			//?
		".",		//¸
		"....",		//¹
		"..",		//º
		"",			//?
		"---",		//¼
		"",			//?
		"-.--",		//¾
		".--",		//¿
		"..",		//À
	};
	static char *restGreek2[] = 
	{
		"..",		//Ú
		"-.--",		//Û
		".-",		//Ü
		".",		//Ý
		"....",		//Þ
		"..",		//ß
		"-.--",		//à
	};
	static char *restGreek3[] = 
	{
		"..",		//ú
		"-.--",		//û
		"---",		//ü
		"-.--",		//ý
		".--",		//þ
	};
		if( L'á'<=c && c<=L'ù' )
			return Greek[c-L'á'];
		else if( L'¢'<=c && c<=L'À' )
			return restGreek1[c-L'¢'];
		else if( L'Ú'<=c && c<=L'à' )
			return restGreek2[c-L'Ú'];
		else if( L'ú'<=c && c<=L'þ' )
			return restGreek3[c-L'ú'];
		else if( L'Á'<=c && c<= L'Ù' )
			return Greek[c-L'Á'];
		else if( 'a'<=c && c<='z' )
			return english[c-'a'];
		else if( 'A'<=c && c<='Z' )
			return english[c-'A'];
		else if( '0'<=c && c<='9' )
			return number[c-'0'];
		else if( c == ' ' )
			return "//";
		else if( c == '.' )
			return "///";
		else
			return "";
}

wchar_t toTextG(const char *s)		//morse to Greek
{
	if(s[0] == '.')//.|
		if(s[1] == '.')//..|
			if(s[2] == '.')//...|
				if(s[3] == '.')//....|
					if(s[4] == '.')	
						return L'5';//.....
					else if(s[4] == '-')
						return L'4';//....-
					else if(s[4] == '\0')
						return L'ç';//....
					else;
				else if(s[3] == '-')//...-|
					if(s[4] == '-')
						return L'3';//...--
					else; 
				else if(s[3] == '\0')
					return L'ó';//...
				else;
			else if(s[2] == '-')//..-|
				if(s[3] == '.')//..-.|
					if(s[4] == '\0')
						return L'ö';//..-.
					else;
				else if(s[3] == '-')//..--|
					if(s[4] == '-')
						return L'2';//..---
					else;
				else;
			else if(s[2] == '\0')
				return L'é';//..
			else;
		else if(s[1] == '-')//.-|
			if(s[2] == '.')//.-.|
				if(s[3] == '.')//.-..|
					if(s[4] == '\0')
						return L'ë';//.-..
					else;
				else if(s[3] == '\0')
					return L'ñ';//.-.
				else;
			else if(s[2] == '-')//.--|
				if(s[3] == '.')//.--.|
					if(s[4] == '\0')
						return L'ð';//.--.
					else;
				else if(s[3] == '-')//.---|
					if(s[4] == '-')
						return L'1';//.----
					else;
				else if(s[3] == '\0')
					return L'ù';//.--
				else;
			else if(s[2] == '\0')
				return L'á';//.-
			else;
		else if(s[1] == '\0')
			return L'å';//.
		else;
	else if(s[0] == '-')//-|
		if(s[1] == '.')//-.|
			if(s[2] == '.')//-..|
				if(s[3] == '.')//-...|
					if(s[4] == '.')
						return L'6';//-....
					else if(s[4] == '\0')
						return L'â';//-...
					else;
				else if(s[3] == '-')//-..-|
					if(s[4] == '\0')
						return L'î';//-..-
					else;
				else if(s[3] == '\0')
					return L'ä';//-..
				else;
			else if(s[2] == '-')//-.-|
				if(s[3] == '.')//-.-.|
					if(s[4] == '\0')
						return L'è';//-.-.
					else;
				else if(s[3] == '-')//-.--|
					if(s[4] == '\0')
						return L'õ';//-.--
					else;
				else if(s[3] == '\0')
					return L'ê';//-.-
				else;
			else if(s[2] == '\0')
				return L'í';//-.
			else;
		else if(s[1] == '-')//--|
			if(s[2] == '.')//--.|
				if(s[3] == '.')//--..|
					if(s[4] == '.')
						return L'7';//--...
					else if(s[4] == '\0')
						return L'æ';//--..
					else;
				else if(s[3] == '-')
					return L'ø';//--.-
				else if(s[3] == '\0')
					return L'ã';//--.
				else;
			else if(s[2] == '-')//---|
				if(s[3] == '.')//---.|
					if(s[4] == '.')
						return L'8';//---..
					else;
				else if(s[3] == '-')//----|
					if(s[4] == '.')
						return L'9';//----.
					else if(s[4] == '-')
						return L'0';//-----
					else if(s[4] == '\0')
						return L'÷';//----
					else;
				else if(s[3] == '\0')
					return L'ï';//---
				else;
			else if(s[2] == '\0')
				return L'ì';//--
			else;
		else if(s[1] == '\0')
			return L'ô';//-
		else;
	else;


	return L'\0';
}






wchar_t toTextE(const char *s)		//morse to English
{
	if(s[0] == '.')//.|
		if(s[1] == '.')//..|
			if(s[2] == '.')//...|
				if(s[3] == '.')//....|
					if(s[4] == '.')	
						return L'5';//.....
					else if(s[4] == '-')
						return L'4';//....-
					else if(s[4] == '\0')
						return L'h';//....
					else;
				else if(s[3] == '-')//...-|
					if(s[4] == '-')
						return L'3';//...--
					else if(s[4] == '\0')
						return L'v';//...-
					else; 
				else if(s[3] == '\0')
					return L's';//...
				else;
			else if(s[2] == '-')//..-|
				if(s[3] == '.')//..-.|
					if(s[4] == '\0')
						return L'f';//..-.
					else;
				else if(s[3] == '-')//..--|
					if(s[4] == '-')
						return L'2';//..---
					else;
				else if(s[3] == '\0')
					return L'u';//..-
				else;
			else if(s[2] == '\0')
				return L'i';//..
			else;
		else if(s[1] == '-')//.-|
			if(s[2] == '.')//.-.|
				if(s[3] == '.')//.-..|
					if(s[4] == '\0')
						return L'l';//.-..
					else;
				else if(s[3] == '\0')
					return L'r';//.-.
				else;
			else if(s[2] == '-')//.--|
				if(s[3] == '.')//.--.|
					if(s[4] == '\0')
						return L'p';//.--.
					else;
				else if(s[3] == '-')//.---|
					if(s[4] == '-')
						return L'1';//.----
					else if(s[4] == '\0')
						return L'j';//.---
					else;
				else if(s[3] == '\0')
					return L'w';//.--
				else;
			else if(s[2] == '\0')
				return L'a';//.-
			else;
		else if(s[1] == '\0')
			return L'e';//.
		else;
	else if(s[0] == '-')//-|
		if(s[1] == '.')//-.|
			if(s[2] == '.')//-..|
				if(s[3] == '.')//-...|
					if(s[4] == '.')
						return L'6';//-....
					else if(s[4] == '\0')
						return L'b';//-...
					else;
				else if(s[3] == '-')//-..-|
					if(s[4] == '\0')
						return L'x';//-..-
					else;
				else if(s[3] == '\0')
					return L'd';//-..
				else;
			else if(s[2] == '-')//-.-|
				if(s[3] == '.')//-.-.|
					if(s[4] == '\0')
						return L'c';//-.-.
					else;
				else if(s[3] == '-')//-.--|
					if(s[4] == '\0')
						return L'y';//-.--
					else;
				else if(s[3] == '\0')
					return L'k';//-.-
				else;
			else if(s[2] == '\0')
				return L'n';//-.
			else;
		else if(s[1] == '-')//--|
			if(s[2] == '.')//--.|
				if(s[3] == '.')//--..|
					if(s[4] == '.')
						return L'7';//--...
					else if(s[4] == '\0')
						return L'z';//--..
					else;
				else if(s[3] == '-')//--.-|
					if(s[4] == '\0')
						return L'q';//--.-
					else;
				else if(s[3] == '\0')
					return L'g';//--.
				else;
			else if(s[2] == '-')//---|
				if(s[3] == '.')//---.|
					if(s[4] == '.')
						return L'8';//---..
					else;
				else if(s[3] == '-')//----|
					if(s[4] == '.')
						return L'9';//----.
					else if(s[4] == '-')
						return L'0';//-----
					else;
				else if(s[3] == '\0')
					return L'o';//---
				else;
			else if(s[2] == '\0')
				return L'm';//--
			else;
		else if(s[1] == '\0')
			return L't';//-
		else;
	else;

	return L'\0';
}