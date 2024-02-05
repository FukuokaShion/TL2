#pragma once
#include <string>
#include <DirectXTex.h>

class TextureConverter
{
public:
	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name = "fliePath">ファイルパス</param>
	/// <param name = "numOptions">オプションの数</param>
	/// <param name = "options">オプション配列</param>
	void ConverterTextureWICToDDS(const std::string& filePath, int numOptions = 0, char* option[] = nullptr);
	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name = "fliePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// フォルダパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);
	static std::wstring ConvertMultiByteStringToWideString(const std::string& String);
	/// <summary>
	/// 使用方法を表示する
	/// </summary>
	static void OutputUsage();
private:
	/// <summary>
	/// DDSテクスチャとしてファイル書き出し
	/// </summary>
	/// <param name = "numOptions">オプションの数</param>
	/// <param name = "options">オプション配列</param>
	void SaveDDSTextureToFile(int numOptions, char* option[]);
private:
	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像のイメージのコンテナ
	DirectX::ScratchImage scratchImage_;

	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;
};
