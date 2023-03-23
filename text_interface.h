#ifndef TEXT_INTERFACE_H_INCLUDED
#define TEXT_INTERFACE_H_INCLUDED

/*
#include <ostream>
#include <array>

#include "user_interface.h"
#include "transformation.h"

class TextInterface : public UserInterface
{
private:
	std::istream& m_is;
	std::ostream& m_os;

	std::u16string printPiece(const Piece& piece, int index);
	std::u16string printPiece(const Piece& piece, const Transformation& t, int idx);

public:
	TextInterface(std::istream& input, std::ostream& output);

	const Piece* getPiece(const PiecesSet& piecesSet) override; // demande la piece, renvoie pointeur de piece
	Coordinate getPosition() override;  // demande une position (translation)
	Transformation getTransformation(const Piece* piece = nullptr) override; // demande une orientation (transformation)

	std::ostream& getMessageOutput() override;
	virtual void clearMessages() override;

	void displayBoard(const Board& board) override; // Mettre à jour l'affichage du plateau de jeu
};
*/


#include <ostream>
#include <array>

#include "user_interface.h"
#include "transformation.h"

class TextInterfaceAscii : public UserInterface
{
private:
	std::istream& m_is;
	std::ostream& m_os;

	std::array<char, 32> printPiece(const Piece& piece, int index);
	std::array<char, 80> printPiece(const Piece& piece, const Transformation& t, int idx);

public:
	TextInterfaceAscii(std::istream& input, std::ostream& output);
	const Piece* getPiece(const PiecesSet& piecesSet) override;
	Coordinate getPosition() override;
	Transformation getTransformation(const Piece* piece = nullptr) override;
	std::ostream& getMessageOutput() override;
	virtual void clearMessages() override;
	void displayBoard(const Board& board) override;
};


#endif // TEXT_INTERFACE_H_INCLUDED
