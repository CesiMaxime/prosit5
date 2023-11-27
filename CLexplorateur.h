#pragma once
using namespace System::IO;
using namespace System;

namespace NS_composants
{
	ref class CLfichier
	{
	public:
		cli::array<String^>^ explorerUnDossier(String^ dossier);
		void effacer(String^ fichier);
		void copier(String^ fichierSource, String^ fichierDestination);
	};
}
