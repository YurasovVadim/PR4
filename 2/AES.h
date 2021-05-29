#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/aes.h>
#include <cryptopp/gost.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/sha.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
using namespace std;
using namespace CryptoPP;
class modAES
{
private:
  string fin;
  string fout;
  string psw;
  string world = "Привет мир";
public:
  modAES() = delete;
  modAES(const string& file_in, const string& file_out, const string& pass): fin(file_in), fout(file_out), psw(pass) {};
  bool encrypt();
  bool decrypt();
};