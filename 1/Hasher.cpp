#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
using namespace std;
int main ()
{
    CryptoPP::SHA1 hash;

    cout <<"Name: " << hash.AlgorithmName() << endl;
    cout << "Digit size: " << hash.DigestSize() << endl;
    cout << "Block size: " << hash.BlockSize() << endl;

    string mess = "";
    string str;
    ifstream f("/home/student/text.txt");
    while (getline(f, str)) {
        mess += str;
    }

    vector<byte> digest(hash.DigestSize());

    hash.Update((const byte*)mess.data(), mess.size());
    hash.Final(digest.data());

    cout << "Message: " << mess << endl;

    cout << "Digest: ";
    CryptoPP::StringSource(digest.data(), digest.size(), true, new CryptoPP::HexEncoder(new CryptoPP::FileSink(cout)));
    cout << endl;
    return 0;
}