#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Tabla base-40
const string TABLE = "ABCDEFGHUKLMNOPQRSTUVWXYZ0123456789 .,?";

// Función para exponenciación modular
long long mod_exp(long long base, long long exp, long long mod) {
	long long result = 1;
	base = base % mod;
	while (exp > 0) {
		if (exp & 1)
			result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}

// Convertir texto a bloques numéricos
vector<long long> text_to_blocks(string message, const string& table) {
	map<char, int> char_to_index;
	for (int i = 0; i < table.size(); ++i)
		char_to_index[table[i]] = i;
	
	// Agregar relleno si la longitud es impar
	if (message.length() % 2 != 0)
		message += '?';
	
	vector<long long> blocks;
	for (size_t i = 0; i < message.length(); i += 2) {
		long long value = char_to_index[message[i]] * 40 + char_to_index[message[i + 1]];
		blocks.push_back(value);
	}
	return blocks;
}

// Convertir bloques numéricos a texto
string blocks_to_text(const vector<long long>& blocks, const string& table) {
	string text;
	for (long long block : blocks) {
		int c1_index = block / 40;
		int c2_index = block % 40;
		text += table[c1_index];
		text += table[c2_index];
	}
	// Eliminar relleno '?'
	while (!text.empty() && text.back() == '?')
		text.pop_back();
	return text;
}

// Cifrar bloques
vector<long long> rsa_encrypt(const vector<long long>& blocks, long long e, long long n) {
	vector<long long> cipher_blocks;
	for (long long m : blocks) {
		long long c = mod_exp(m % n, e, n);
		cipher_blocks.push_back(c);
	}
	return cipher_blocks;
}

// Descifrar bloques
vector<long long> rsa_decrypt(const vector<long long>& cipher_blocks, long long d, long long n) {
	vector<long long> decrypted_blocks;
	for (long long c : cipher_blocks) {
		long long m = mod_exp(c, d, n);
		decrypted_blocks.push_back(m);
	}
	return decrypted_blocks;
}

int main() {
	long long e = 13, n = 2537, d = 937;
	vector<string> messages = {"BUENAS NOCHES", "BUENAS TARDES", "COMO ESTAS"};
	
	for (const string& message : messages) {
		cout << "Mensaje: " << message << endl;
		
		// a. Bloques numéricos
		vector<long long> blocks = text_to_blocks(message, TABLE);
		cout << "a. Bloques numéricos: ";
		for (long long b : blocks)
			cout << b << " ";
		cout << endl;
		
		// b. Bloques cifrados
		vector<long long> cipher_blocks = rsa_encrypt(blocks, e, n);
		cout << "b. Bloques cifrados: ";
		for (long long c : cipher_blocks)
			cout << c << " ";
		cout << endl;
		
		// c. Bloques descifrados
		vector<long long> decrypted_blocks = rsa_decrypt(cipher_blocks, d, n);
		cout << "c. Bloques descifrados: ";
		for (long long m : decrypted_blocks)
			cout << m << " ";
		cout << endl;
		
		// d. Texto recuperado
		string recovered_text = blocks_to_text(decrypted_blocks, TABLE);
		cout << "d. Texto recuperado: " << recovered_text << endl;
		cout << "------------------------" << endl;
	}
	
	return 0;
}
