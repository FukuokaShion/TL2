#include <cstdio>
#include <cstdlib>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,	//�A�v���P�[�V�����̃p�X
	kFilePath,			//�n���ꂽ�t�@�C���̃p�X
	NumArgument
};

int main(int argc,char* argv[]) {
	//�R�}���h���C�������w�薳��
	if (argc < NumArgument) {
		//�g������\������
		TextureConverter::OutputUsage();
		return 0;
	}
	
	//���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�I�v�V�����̐�
	int numOption = argc - NumArgument;
	//�I�v�V�����z��(�_�u���|�C���^)
	char** options = argv + NumArgument;

	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	return 0;
}