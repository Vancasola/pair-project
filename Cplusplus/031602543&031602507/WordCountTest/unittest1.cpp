#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\WordCount\Count.h"
#include "..\WordCount\FileIO.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)	//���Զ�ȡ�ļ�����
		{
			string charBuf;
			vector<string> linesBuf;
			const char* inputFileName = "../WordCount/input/";
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf),false);
		}
		TEST_METHOD(TestMethod2)	//��������ļ�����
		{
			int characterCount = 0;
			int lineCount = 0;
			int wordCount = 0;
			const char* outputFileName = "../WordCount/output/";
			vector<map<string, int>::iterator> topX;
			Assert::AreEqual(FileIO::outputToFile(characterCount, wordCount, lineCount, outputFileName, topX), false);
		}
		TEST_METHOD(TestMethod3)	//�����ַ�ͳ�ƺ���
		{
			int characterCount = 0;
			const char* inputFileName = "../WordCountTest/input1.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countCharNum(charBuf) - 17,9);
		}
		TEST_METHOD(TestMethod4)	//���Ե���ͳ�ƹ���
		{
			int weightValue = 0;
			int characterCount = 0;
			const char* inputFileName = "../WordCountTest/input2.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf,weightValue,-1), 2);
		}
		TEST_METHOD(TestMethod5)	//���Ե�����Ȩ��ʱ���ʸ���ͳ���Ƿ�Ӱ��
		{
			int weightValue = 1;
			int characterCount = 0;
			const char* inputFileName = "../WordCountTest/input3.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf, weightValue, -1), 2);
		}
		TEST_METHOD(TestMethod6)	//������Ȩ�ص��ʴ�Ƶͳ�ƹ���
		{
			int weightValue = 0;
			int topX = 10;
			const char* inputFileName = "../WordCountTest/input4.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf, weightValue, -1), 11);
			vector<map<string, int>::iterator> topXWord = count.countTopXWord(topX);
			Assert::AreEqual(topXWord[0]->first,string( "abcd"));
			Assert::AreEqual(-topXWord[0]->second, 4);
			Assert::AreEqual(topXWord[1]->first, string("asda"));
			Assert::AreEqual(-topXWord[1]->second, 3);
			Assert::AreEqual(topXWord[2]->first, string("abce"));
			Assert::AreEqual(-topXWord[2]->second, 1);
			Assert::AreEqual(topXWord[3]->first, string("abcf"));
			Assert::AreEqual(-topXWord[3]->second, 1);
			Assert::AreEqual(topXWord[4]->first, string("abcg"));
			Assert::AreEqual(-topXWord[4]->second, 1);
			Assert::AreEqual(topXWord[5]->first, string("abch"));
			Assert::AreEqual(-topXWord[5]->second, 1);
		}
		TEST_METHOD(TestMethod7)	//������Ȩ�ص��ʴ�Ƶͳ�ƹ���
		{
			int weightValue = 1;
			int topX = 10;
			const char* inputFileName = "../WordCountTest/input5.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf, weightValue, -1), 11);
			vector<map<string, int>::iterator> topXWord = count.countTopXWord(topX);
			Assert::AreEqual(topXWord[0]->first, string("abcd"));
			Assert::AreEqual(-topXWord[0]->second, 31);
			Assert::AreEqual(topXWord[1]->first, string("abce"));
			Assert::AreEqual(-topXWord[1]->second, 10);
			Assert::AreEqual(topXWord[2]->first, string("abcf"));
			Assert::AreEqual(-topXWord[2]->second, 10);
			Assert::AreEqual(topXWord[3]->first, string("abcg"));
			Assert::AreEqual(-topXWord[3]->second, 10);
			Assert::AreEqual(topXWord[4]->first, string("asda"));
			Assert::AreEqual(-topXWord[4]->second, 3);
			Assert::AreEqual(topXWord[5]->first, string("abch"));
			Assert::AreEqual(-topXWord[5]->second, 1);
		}
		TEST_METHOD(TestMethod8)	//���Դ���ͳ�ƹ���
		{
			int topX = 10;
			const char* inputFileName = "../WordCountTest/input6.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf, 0, 2), 5);
			vector<map<string, int>::iterator> topXPhrase = count.countTopXPhrase(topX);
			Assert::AreEqual(topXPhrase[0]->first, string("monday tuesday"));
			Assert::AreEqual(-topXPhrase[0]->second, 1);
			Assert::AreEqual(topXPhrase[1]->first, string("tuesday wednesday"));
			Assert::AreEqual(-topXPhrase[1]->second, 1);
			Assert::AreEqual(topXPhrase[2]->first, string("wednesday thursday"));
			Assert::AreEqual(-topXPhrase[2]->second, 1);
		}
		TEST_METHOD(TestMethod9)	//��������ͳ�ƹ���
		{
			const char* inputFileName = "../WordCountTest/input7.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countLineNum(linesBuf), 6);

		}
		TEST_METHOD(TestMethod10)	//�ı�Ϊ cvpr2018 ������ȡ������������й���
		{
			const char* inputFileName = "../WordCountTest/input8.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countCharNum(charBuf) - 979 * 17,1196950);			
			Assert::AreEqual(count.countLineNum(linesBuf), 1958);
			Assert::AreEqual(count.countWordNum(linesBuf, 0, -1), 120374);
			vector<map<string, int>::iterator> topXWord = count.countTopXWord(10);
			Assert::AreEqual(topXWord[0]->first, string("that"));
			Assert::AreEqual(-topXWord[0]->second, 1757);
			Assert::AreEqual(topXWord[1]->first, string("with"));
			Assert::AreEqual(-topXWord[1]->second, 1475);
			Assert::AreEqual(topXWord[2]->first, string("this"));
			Assert::AreEqual(-topXWord[2]->second, 1444);
			Assert::AreEqual(topXWord[3]->first, string("image"));
			Assert::AreEqual(-topXWord[3]->second, 1224);
			Assert::AreEqual(topXWord[4]->first, string("from"));
			Assert::AreEqual(-topXWord[4]->second, 1097);
			Assert::AreEqual(topXWord[5]->first, string("network"));
			Assert::AreEqual(-topXWord[5]->second, 973);
			Assert::AreEqual(topXWord[6]->first, string("learning"));
			Assert::AreEqual(-topXWord[6]->second, 971);
			Assert::AreEqual(topXWord[7]->first, string("which"));
			Assert::AreEqual(-topXWord[7]->second, 808);
			Assert::AreEqual(topXWord[8]->first, string("model"));
			Assert::AreEqual(-topXWord[8]->second, 762);
			Assert::AreEqual(topXWord[9]->first, string("images"));
			Assert::AreEqual(-topXWord[9]->second, 732);
		}
		TEST_METHOD(TestMethod11)	//���Ե���֮���ж���ָ����Ĵ���
		{
			const char* inputFileName = "../WordCountTest/input9.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf, 0, 2), 4);
			vector<map<string, int>::iterator> topXPhrase = count.countTopXPhrase(10);
			Assert::AreEqual(topXPhrase[0]->first, string("this (<apple"));
			Assert::AreEqual(-topXPhrase[0]->second, 1);
		}
		TEST_METHOD(TestMethod12)	//���Ե���֮���в��Ϸ����ʵĴ���
		{
			const char* inputFileName = "../WordCountTest/input10.txt";
			string charBuf;
			vector<string> linesBuf;
			Assert::AreEqual(FileIO::readFile(inputFileName, charBuf, linesBuf), true);
			Count count;
			Assert::AreEqual(count.countWordNum(linesBuf, 0, 2), 4);
			vector<map<string, int>::iterator> topXPhrase = count.countTopXPhrase(10);
			Assert::AreEqual(topXPhrase[0]->first, string("delicious apple"));
			Assert::AreEqual(-topXPhrase[0]->second, 1);
		}
	};
}