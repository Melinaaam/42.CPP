#!/bin/sh

BOLD="\033[1m"
GREEN="\033[32m"
RED="\033[31m"
CYAN="\033[36m"
RESET="\033[0m"

BIN="./RPN"

valid_tests='
8 9 * 9 - 9 - 9 - 4 - 1 +|42
7 7 * 7 -|42
1 2 * 2 / 2 * 2 4 - +|0
5 1 2 + 4 * + 3 -|14
9 3 /|3
6 2 * 3 /|4
0 0 +|0
9 9 *|81
1 2 3 + +|6
'

invalid_tests='
1 +
8 9 * *
9 0 /
abc
1 2 + 3
(1 2 +)
""
'

echo -e "${CYAN}${BOLD}Testing valid expressions...${RESET}"
echo "$valid_tests" | while IFS='|' read expr expected; do
	[ -z "$expr" ] && continue
	output=$($BIN "$expr" 2>&1)
	if [ "$output" = "$expected" ]; then
		echo -e "✅ \"$expr\" -> ${GREEN}$output${RESET}"
	else
		echo -e "❌ \"$expr\" -> ${RED}Expected $expected, got: $output${RESET}"
	fi
done

echo ""
echo -e "${CYAN}${BOLD}Testing invalid expressions...${RESET}"
echo "$invalid_tests" | while read expr; do
	[ -z "$expr" ] && continue
	$BIN "$expr" > /dev/null 2>&1
	if [ $? -ne 0 ]; then
		echo -e "✅ \"$expr\" -> ${GREEN}Error detected${RESET}"
	else
		echo -e "❌ \"$expr\" -> ${RED}No error detected${RESET}"
	fi
done
