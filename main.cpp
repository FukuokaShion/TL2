#include <cstdio>
#include <cstdlib>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス
	NumArgument
};

int main(int argc,char* argv[]) {
	//コマンドライン引数指定無し
	if (argc < NumArgument) {
		//使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}
	
	//ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//オプションの数
	int numOption = argc - NumArgument;
	//オプション配列(ダブルポインタ)
	char** options = argv + NumArgument;

	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	return 0;
}