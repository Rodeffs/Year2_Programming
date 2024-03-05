<?php
/* Imagine a lot of code here */ 
$very_bad_unclear_name = "15 chicken wings";

// Write your code here:


// 1 пункт

// Ссылка как в C и C++
$order = &$very_bad_unclear_name;

// Конкатенация через .
$order.=", two number 9s, a number 9 large, a number 6 with extra dip, a number 7, two number 45s, one with cheese, and a large soda";
  
// Don't change the line below
echo "\nYour order is: $very_bad_unclear_name.";

echo "\n\n";


// 2 пункт

$x = 420;

echo "int = $x";

echo "\n";

$f = 19.8588925893205832953839;

echo "float = $f\n";

$g = 96 / 8;

echo "twelve = $g\n";

$last_month = 1187.23;

$this_month = 1089.98;

echo "difference = ", $last_month - $this_month, "\n\n";


// 11 пункт (3 пункт?)

$num_languages = 4;

$months = 11;

$days = 16 * $months;

$days_per_language = $days / $num_languages;

echo "days per language = $days_per_language\n\n";


// 12 пункт

echo "8^2 = ", 8**2, "\n\n";


// 13 пункт

$my_num = 24;

$answer = $my_num;

$answer += 2;

$answer *= 2;

$answer -= 2;

$answer /= 2;

$answer -= $my_num;

echo "answer = $answer\n\n";


// 14 пункт

$a = 10;

$b = 3;

$r = $a % $b;

echo "a%b = ", $r, "\n";

// if оператор тоже как в C
if ($a % $b == 0) {
	echo "Делится\n";
}
else {
	echo "Делится с остатком $r\n";  
}

$st = pow(2, 10);

echo "2^10 = $st\n";

$sq = sqrt(245);

echo "245^0.5 = $sq\n";

$ls = [4, 2, 5, 19, 13, 0, 10];

$res = 0;

// foreach как в Питоне for i in ls 
foreach ($ls as $i) {
	$res += pow($i, 2);
}

$res = sqrt($res);

echo "корень суммы квадратов = $res\n";

$sq379 = sqrt(379);

$val1 = round($sq379);

echo "округление 379^0.5 до целых = $val1\n";

$val01 = round($sq379, 1);

echo "	 до десятых = $val01\n";

$val001 = round($sq379, 2);

echo "	 до сотых = $val001\n";

$sq587 = sqrt(587);

// Ассоциативный массив
$arr = array("floor"=>floor($sq587), "ceil"=>ceil($sq587));

$o1 = $arr['ceil'];

$o2 = $arr['floor'];

echo "округление 587^0.5 в большую сторону = $o1\n";
echo "округление 587^0.5 в меньшую сторону = $o2\n";

$num_arr = [4, -2, 5, 19, -130, 0, 10];

$min_num = min($num_arr);

echo "min = $min_num\n";

$max_num = max($num_arr);

echo "max = $max_num\n";

echo "random number = ", rand(0, 10), "\n";

$rand_arr = [];

// Цикл for буквально как в C
for ($i = 0; $i < 10; $i++) {
	array_push($rand_arr, rand());
}

echo "random array:\n";

foreach ($rand_arr as $i) {
	echo "$i ";
}

$a = 789;

$b = 1500;

$mod = abs($a - $b);

echo "\nabs(a - b) = $mod\n";

$num_arr2 = [1, 2, -1, -2, 3, -3];

$abs_arr = [];

foreach ($num_arr2 as $i) {
	array_push($abs_arr, abs($i));
}

$num = 30;

$divisors = [1];

for ($i = 2; $i < $num / 2 + 1; $i++) {
	if ($num % $i == 0) {
		array_push($divisors, $i);
	}
}

array_push($divisors, $num);

echo "все делители числа $num:\n";

foreach ($divisors as $i) {
	echo "$i ";
}

$num_arr3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

$i = 0;

$sum = 0;

while ($sum < 10) {
	$sum += $num_arr3[$i];
	$i++;
}

echo "\nчтобы сумма была больше 10, нужно сложить $i первых элементов\n\n";


// 15 пункт

function printStringReturnNumber() {
	echo "строка\n";
	return 100;
}

$my_num = printStringReturnNumber();

echo "значение функции = $my_num\n\n";


// 16 пункт

function increaseEnthusiasm($str) {
	return $str.="!";
}

echo increaseEnthusiasm("ФТИ+1"), "\n";

function repeatThreeTimes($str) {
	for ($i = 0; $i < 3; $i++) {
		echo $str;
	}
}

echo repeatThreeTimes("Я ТЕБЕ ГОВОРИЛ, ЧТО ТАКОЕ БЕЗУМИЕ?"), "\n";

echo increaseEnthusiasm(increaseEnthusiasm(repeatThreeTimes("ААААА"))), "\n";

function cut(&$str, $remain = 10) {
	$str = substr($str, 0, $remain);
}

$str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

cut($str);

echo $str, "\n";

$arr_recursive = [10, 20, 30, 40, 50];

function recur($arr, $i = 0) {
	echo $arr[$i], " ";
	if ($i + 1 < count($arr)) {
		recur($arr, $i + 1);
	}
}

recur($arr_recursive);

echo "\n";

function sum_digits($num) {
	$sum = 0;
	$copy = $num;
	while ($copy >= 1) {
		$sum += $copy % 10;
		$copy = floor($copy / 10);
	}
	echo "$sum\n";
	if ($sum > 9) {
		sum_digits($sum);
	}
}

$num_to_sum = 357298429553939842;

echo "изначальное число $num_to_sum, сумма (суммы) его цифр:\n", sum_digits($num_to_sum), "\n";


// 17 пункт

$x_arr = [];

for ($i = 1; $i < 11; $i++) {
	array_push($x_arr, str_repeat("x", $i));
}

foreach ($x_arr as $i) {
	echo "$i\n";
}

function arrayFill($sym, $t) {
	$filled = [];
	for ($i = 0; $i < $t; $i++) {
		array_push($filled, $sym);
	}
	return $filled;
}

$arr_arr = arrayFill("arr", 10);

foreach ($arr_arr as $i) {
	echo "$i ";
}

$two_dim = [[1, 2, 3], [4, 5], [6]];

$total = 0;

for ($i = 0; $i < count($two_dim); $i++) {
	for ($j = 0; $j < count($two_dim[$i]); $j++) {
		$total += $two_dim[$i][$j];
	}
}

echo "\nсумма элементов двумерного массива равна $total\n";

$elem = 1;

$three_three = [];

for ($i = 0; $i < 3; $i++) {
	for ($j = 0; $j < 3; $j++) {
		$three_three[$i][$j] = $elem;
		$elem++;
	}
}

for ($i = 0; $i < 3; $i++) {
	for ($j = 0; $j < 3; $j++) {
		echo $three_three[$i][$j], " ";
	}
}

$mas = [2, 5, 3, 9];

$result = $mas[0] * $mas[1] + $mas[2] * $mas[3];

echo "\nresult = $result\n";

$user = [];

$user = array("name"=>"Александр", "surname"=>"Александров", "patronymic"=>"Александрович");

echo $user['surname'], " ", $user['name'], " ", $user['patronymic'], "\n";

$date = array("year"=>2024, "month"=>3, "day"=>5);

echo $date['year'], "-", $date['month'], "-", $date['day'], "\n";

$arr = ['a', 'b', 'c', 'd', 'e'];

$len = count($arr);

echo "arr count = ", $len;

echo "\nlast element = ", $arr[$len-1];

echo "\nsecond to last = ", $arr[$len-2];

echo "\n\n";


// 18 пункт

function more_than_10($x, $y) {
	return ($x + $y) > 10;
}

function equal($x, $y) {
	return $x == $y;
}

// Тернарный оператор как и в C
echo $test? "\n" : "верно\n";

$age = 45;

if ($age < 10 || $age > 99) {
	echo "age за пределами\n";
}
else {
	$digit_sum = $age % 10 + floor($age / 10) % 100;
	if ($digit_sum <= 9) {
		echo "сумма цифр однозначна\n";
	}
	else {
		echo "сумма цифр двузначна\n";
	}
}

$arr = [5, 60, 87];

if (count($arr) == 3) {
	echo "сумма элементов массива = ", $arr[0] + $arr[1] + $arr[2];
}

echo "\n\n";


