#include "Node.h"
string morse_code[36][2] = { {".","E"},{"-","T"},{"..","I"},{".-","A"},{"-.","N"},{"--","M"},{"...","S"},{"..-","U"},{".-.","R"},
	{".--","W"},{"-..","D"},{"-.-","K"},{"--.","G"},{"---","O"},{"....","H"},{"...-","V"},{"..-.","F"},{".-..","L"},{".--.","P"},{".---","J"},
	{"-...","B"},{"-..-","X"},{"-.-.","C"},{"-.--","Y"},{"--..","Z"},{"--.-","Q"},{".....","5"},{"....-","4"},{"...--","3"},{"..--","2"},{".----","1"},{"-....","6"},{"--...","7"},{"---.","8"},{"----","9"},{"-----","0"}};

int main() {
	//Make the Morse Code Tree
	TreeNode tree;
	TreeNode::Node* root = tree.newNodeAppending();
	int n = (sizeof(morse_code) / sizeof(morse_code[0]));
	for (int i = 0; i < n; i++) {
		root = tree.addNode(root, morse_code[i][0], morse_code[i]);
	}
	char choice;
	cout << "Welcome to the Morse Code Simulator!\nPlease choose either to input morse code to translate to English or vice versa. Anything else will cause termination ";
	
	do {
		cout << "\nA. Morse Code to English\nB. English to Morse Code\nAnything else will terminate program!\nChoice: ";
		cin >> choice;

		
		switch (choice) {
		case 'A':
		case 'a': {
			cout << "\nAppendix" << endl;
			cout << "========" << endl;
			cout << "Letter:\tM.Code:" << endl;
			cout << " A \t .-\n B \t -...\n C \t -.-.\n D \t -..\n E \t .\n F \t ..-.\n G \t --.\n H \t ....\n I \t ..\n J \t .---\n K \t -.-\n L \t .-..\n M \t --\n N \t -.\n" <<
				" O \t --- \n P \t .--.\n Q \t --.- \n R \t .-.\n S \t ...\n T \t - \n W \t .--\n X \t -..- \n Y \t -.--\n Z \t -...\n " <<
				"0 \t ---- - \n 1 \t .----\n 2 \t .--- \n 3 \t ...--\n 4 \t ....- \n 5 \t .....\n 6 \t -....\n 7 \t --...\n 8 \t ---.\n 9 \t ----" << endl;
			string message;
			cout << "\nEnter a message in Morse Code to be translated into English (0-9) & (A-Z).\nUse '|' and '/' to represent a whitespace and ending of a letter, respectively." << endl;
			cout << "Example: -.-./---/--/|.../-.-./../|../../../ is COM SCI III" << endl;
			cout << "\nMorse Code: ";
			cin >> message;

			string morse_mess = "";

			char char_arr[100];

			strcpy_s(char_arr, message.c_str());

			string letter = "";

			for (int i = 0; i < message.length();i++) {
				if (char_arr[i] == '/') {
					morse_mess += tree.retrieveChar(root, letter, "[");
					letter = "";
				}
				else if (char_arr[i] == '|') {
					morse_mess += " ";
				}
				else {
					letter += char_arr[i];
				}
			}
			cout << "Your message from Morse Code to English is: " << morse_mess << "\n" << endl;
			break;
		  }//Case A and B

		case 'B':
		case 'b':
		{
			cout << "\nAppendix" << endl;
			cout << "========" << endl;
			cout << "Letter:\tM.Code:" << endl;
			cout << " A \t .-\n B \t -...\n C \t -.-.\n D \t -..\n E \t .\n F \t ..-.\n G \t --.\n H \t ....\n I \t ..\n J \t .---\n K \t -.-\n L \t .-..\n M \t --\n N \t -.\n" <<
				" O \t --- \n P \t .--.\n Q \t --.- \n R \t .-.\n S \t ...\n T \t - \n W \t .--\n X \t -..- \n Y \t -.--\n Z \t -...\n " <<
				"0 \t ---- - \n 1 \t .----\n 2 \t .--- \n 3 \t ...--\n 4 \t ....- \n 5 \t .....\n 6 \t -....\n 7 \t --...\n 8 \t ---.\n 9 \t ----" << endl;
			
			string message;
			cout << "\nEnter a message in English to be translated into Morse Code (0-9) & (A-Z).\nUse '_' (Underscore) to represent a whitespace at the end of a word." << endl;
			cout << "Please Note!: '/' and '|' indicates the end of a letter and a whitespace, respectively " << endl;
			cout << "Example: COM SCI III is -.-./---/--/|.../-.-./../|../../../  " << endl;
			cout << "\nEnglish Message: ";
			cin >> message;
			
			string morse_mess = "";

			for (int i = 0; i < message.length();i++) {
				if (message[i] == '_') {
					morse_mess += '|';
				}
				else {
					morse_mess += tree.retrieveMorse(root, "", string(1,message[i]));
					morse_mess += '/';
				}
			}
			cout << "Your message from English to Morse Code is: " << morse_mess << endl;
			break;
		} //Case 'B' and Case 'b'
		default: {
			choice = 'x';
			break;
		  }
		}
	} while (choice  == 'A' || choice == 'a'|| choice == 'B' || choice == 'b');
	cout << "\nHey! Thanks for playing!" << endl;
	return 0;
 }
