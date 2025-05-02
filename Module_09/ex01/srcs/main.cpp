#include "RPN.hpp"
/*
| Expression                    | Résultat attendu |
| ----------------------------- | ---------------- |
| `"8 9 * 9 - 9 - 9 - 4 - 1 +"` | `42`             |
| `"7 7 * 7 -"`                 | `42`             |
| `"1 2 * 2 / 2 * 2 4 - +"`     | `0`              |
| `"5 1 2 + 4 * + 3 -"`         | `14`             |
| `"9 3 /"`                     | `3`              |
| `"6 2 * 3 /"`                 | `4`              |

| Expression         | Motif du problème        |
| ------------------ | ------------------------ |
| `"1 +"`            | Pas assez d'opérandes    |
| `"8 9 * *"`        | Pas assez d'opérandes    |
| `"9 0 /"`          | Division par zéro        |
| `"abc"`            | Caractère non reconnu    |
| `"1 2 + 3"`        | Trop d’éléments restants |
| `"1 2 ( + )"`      | Parenthèses interdites   |
| `""` (chaîne vide) | Aucune expression        |

| Expression            | Explication                                  |
| --------------------- | -------------------------------------------- |
| `"0 0 +"`             | Zéro + zéro                                  |
| `"9 9 *"`             | Grand résultat (81)                          |
| `"1 2 3 + +"`         | Empile 1, puis calcule 2+3 = 5, puis 1+5 = 6 |
| `"5 1 2 + 4 * + 3 -"` | Test complet avec priorité implicite         |


*/
int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED << "Error : argc < 2" << RESET << std::endl;
		return 1;
	}

	RPN calculator;
	try {
		calculator.evaluate(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << RED << "Error : bad arguments" << RESET << std::endl;
		return 1;
	}
	return 0;
}
