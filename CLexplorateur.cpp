#include "pch.h"
#include "CLexplorateur.h"

namespace NS_composants
{
	cli::array<String^>^ CLfichier::explorerUnDossier(String^ dossier)
	{
		// Code pour explorer le dossier et récupérer les fichiers
		// Par exemple, lister les fichiers dans un tableau
		array<String^>^ files = Directory::GetFiles(dossier);
		return files;
	}

	void CLfichier::effacer(String^ fichier)
	{
		System::IO::File::Delete(fichier);
	}

	void CLfichier::copier(String^ fichierSource, String^ fichierDestination)
	{
		String^ nomDeFichierExtension = System::IO::Path::GetFileName(fichierSource);
		System::IO::File::Copy(fichierSource, fichierDestination + "\\" + nomDeFichierExtension);
	}
}
