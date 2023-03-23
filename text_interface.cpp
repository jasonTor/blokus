/*
#include <limits>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <locale>
#include <codecvt>

#include "text_interface.h"
#include "board.h"

TextInterface::TextInterface(std::istream& input, std::ostream& output) :
	m_is{input},
	m_os{output}
{}


std::u16string TextInterface::printPiece(const Piece& piece, int idx)
{
	Coordinate max{8, 4};

	std::u16string display(max.x * 2 * max.y, ' ');
	for (auto&& c : piece) {
		display[(max.y - c.y - 2) * max.x * 2 + c.x * 2] = u'█';
		display[(max.y - c.y - 2) * max.x * 2 + c.x * 2 + 1] = u'█';
	}

	display[50] = (idx / 10) + '0';
	display[51] = (idx % 10) + '0';

	return display;
}

std::u16string TextInterface::printPiece(const Piece& piece, const Transformation& t, int idx)
{
	Coordinate max{10, 8};

	std::u16string display(max.x * max.y * 2, ' ');
	std::vector<Coordinate> coords;
	Coordinate min{0, 0};
	std::transform(piece.begin(), piece.end(), std::back_inserter(coords),
		[&t, &min](const Coordinate& c) {
			Coordinate transformed = c * t;
			if (transformed.x < min.x)
				min.x = transformed.x;
			if (transformed.y < min.y)
				min.y = transformed.y;
			return transformed;
		}
	);

	display[(max.y + min.y - 3) * max.x * 2 + 2] = '0';
	display[- min.x * 2 + 6] = '0';
	for (int x=2 ; x<max.x-1 ; x++) {
		display[(max.y + min.y - 3) * max.x * 2 + x * 2] = u'─';
		display[(max.y + min.y - 3) * max.x * 2 + x * 2 + 1] = u'─';
	}
	for (int y=1 ; y<max.y-1 ; y++) {
		display[y * max.x * 2 - min.x * 2 + 6] = u'▕';
	}

	for (auto&& c : coords) {
		display[(max.y - (c.y - min.y) - 3) * max.x * 2 + c.x * 2 - min.x * 2 + 6] = u'█';
		display[(max.y - (c.y - min.y) - 3) * max.x * 2 + c.x * 2 - min.x * 2 + 6 + 1] = u'█';
	}

	display[148] = idx + '0';

	return display;
}



const Piece* TextInterface::getPiece(const PiecesSet& piecesSet)
{
	std::vector<std::u16string> lines;
	std::array<std::u16string, 4> ls;
	int i=0;
	for (const Piece* p : piecesSet.getCollection()) {
		std::u16string d = printPiece(*p, i);
		for (int j=0 ; j<4 ; j++) {
			std::copy(d.begin() + 8 * 2 * j, d.begin() + 8 * 2 * (j + 1), std::back_inserter(ls[j]));
		}
		i++;
		if (i % 7 == 0) {
			for (auto&& l: ls) {
				lines.emplace_back(std::move(l));
				l.clear();
			}
		}
	}
	for (auto&& l: ls) {
		if (!l.empty())
			lines.emplace_back(std::move(l));
	}

	std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
	for (int i=0 ; i<lines.size() ; i++) {
		if (i % 4 == 0)
			m_os << "\n";
		m_os << converter.to_bytes(lines[i]) << "\n";
	}
	m_os << "\n";

	m_os << "Piece ? ";
	int piece;
	m_is >> piece;
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (piece < 0 || piece >= piecesSet.size())
		return nullptr;
	return *std::next(piecesSet.getCollection().begin(), piece);
}

Coordinate TextInterface::getPosition()
{
	m_os << "Position ? ";
	int x, y;
	m_is >> x >> y;
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	Coordinate c{x, y};
	if (Board::validate(c))
		return c;
	else
		return Coordinate{0, 0};
}

Transformation TextInterface::getTransformation(const Piece* piece)
{
	if (piece) {
		const Piece& p = *piece;
		int i=0;
		std::array<std::u16string, 8> ls;
		for (auto&& t : TRANSFORMATIONS) {
			std::u16string d = printPiece(p, t, i);
			for (int j=0 ; j<8 ; j++) {
				std::copy(d.begin() + 10 * 2 * j, d.begin() + 10 * 2 * (j + 1), std::back_inserter(ls[j]));
				ls[j].append(u" ┃ ");
			}
			i++;
		}

		std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
		for (int i=0 ; i<ls.size() ; i++) {
			m_os << converter.to_bytes(ls[i]) << "\n";
		}
		m_os << "\n";
	}


	m_os << "Orientation ? ";
	int t;
	m_is >> t;
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (t >= 0 && t < TRANSFORMATIONS.size())
		return TRANSFORMATIONS[t];
	else
		return Transformation::None;
}

std::ostream& TextInterface::getMessageOutput()
{
	return m_os;
}

void TextInterface::clearMessages()
{
	// no-op
}

void TextInterface::displayBoard(const Board& board)
{
	m_os << std::right;
	m_os << "     ";
	for (int column = 1 ; column < Board::SIZE ; column+=2) {
		m_os << std::setw(2) << column << "  ";
	}
	m_os << "\n";
	for (int line = Board::SIZE - 1 ; line >= 0 ; line--) {
		if (line % 2 == 0)
			m_os << std::right << std::setw(2) << line << " ";
		else
			m_os << "   ";
		for (int column = 0 ; column < Board::SIZE ; column++) {
			switch (board.getColor(Coordinate{column, line})) {
				case Color::Empty:
					m_os << ((line + column == 0) ? "🭼▁" :
						(line + column == Board::SIZE * 2 - 2) ? "▔🭾" :
						((line + column) % 2 == 1) ? "░░" : "  ");
					break;
				case Color::Blue:
					m_os << "\033[34m" << "██" << "\033[0m";
					break;
				case Color::Yellow:
					m_os << "\033[33m" << "██" << "\033[0m";
					break;
				case Color::Red:
					m_os << "\033[31m" << "██" << "\033[0m";
					break;
				case Color::Green:
					m_os << "\033[32m" << "██" << "\033[0m";
					break;
			}
		}
		if (line % 2 == 1)
			m_os << std::left << " " <<  std::setw(2) << line;
		m_os << "\n";
	}

	m_os << "   ";
	m_os << std::right;
	for (int column = 0 ; column < Board::SIZE ; column+=2) {
		m_os << std::setw(2) << column << "  ";
	}
	m_os << std::endl;
}
*/

#include <limits>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>

#include "text_interface.h"
#include "board.h"

TextInterfaceAscii::TextInterfaceAscii(std::istream& input, std::ostream& output) :
	m_is{input},
	m_os{output}
{}


std::array<char, 32> TextInterfaceAscii::printPiece(const Piece& piece, int idx)
{
	Coordinate max{8, 4};

	std::array<char, 32> display;
	std::fill(display.begin(), display.end(), ' ');
	for (auto&& c : piece) {
		display[(max.y - c.y - 2) * max.x + c.x] = '#';
	}

	display[24] = (idx / 10) + '0';
	display[25] = (idx % 10) + '0';

	return display;
}

std::array<char, 80> TextInterfaceAscii::printPiece(const Piece& piece, const Transformation& t, int idx)
{
	Coordinate max{10, 8};

	std::array<char, 80> display;
	std::vector<Coordinate> coords;
	Coordinate min{0, 0};
	std::transform(piece.begin(), piece.end(), std::back_inserter(coords),
		[&t, &min](const Coordinate& c) {
			Coordinate transformed = c * t;
			if (transformed.x < min.x)
				min.x = transformed.x;
			if (transformed.y < min.y)
				min.y = transformed.y;
			return transformed;
		}
	);

	std::fill(display.begin(), display.end(), ' ');
	display[(max.y + min.y - 3) * max.x] = '0';
	display[- min.x + 4] = '0';
	for (int x=1 ; x<max.x ; x++) {
		display[(max.y + min.y - 3) * max.x + x] = '-';
	}
	for (int y=1 ; y<max.y-1 ; y++) {
		display[y * max.x - min.x + 4] = '|';
	}

	for (auto&& c : coords) {
		display[(max.y - (c.y - min.y) - 3) * max.x + c.x - min.x + 4] = '#';
	}

	display[74] = idx + '0';

	return display;
}

const Piece* TextInterfaceAscii::getPiece(const PiecesSet& piecesSet)
{
	std::vector<std::string> lines;
	std::array<std::string, 4> ls;
	int i=0;
	for (const Piece* p : piecesSet.getCollection()) {
		std::array<char, 32> d = printPiece(*p, i);
		for (int j=0 ; j<4 ; j++) {
			std::copy(d.begin() + 8 * j, d.begin() + 8 * (j + 1), std::back_inserter(ls[j]));
		}
		i++;
		if (i % 7 == 0) {
			for (auto&& l: ls) {
				lines.emplace_back(std::move(l));
				l.clear();
			}
		}
	}
	for (auto&& l: ls) {
		if (!l.empty())
			lines.emplace_back(std::move(l));
	}

	for (int i=0 ; i<lines.size() ; i++) {
		if (i % 4 == 0)
			m_os << "\n";
		m_os << lines[i] << "\n";
	}
	m_os << "\n";

	m_os << "Choisissez une Piece a jouer : ";
	int piece;
	m_is >> piece;
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (piece < 0 || piece >= piecesSet.size())
		return nullptr;
	return *std::next(piecesSet.getCollection().begin(), piece);
}

Coordinate TextInterfaceAscii::getPosition()
{
	m_os << "Choisissez la position, " << std::endl;
	int x, y;
	m_os << "Coordonnee x : ";
	m_is >> x;
	m_os << "Coordonnee y : ";
	m_is >> y;
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	Coordinate c{x, y};
	if (Board::validate(c))
		return c;
	else
		return Coordinate{0, 0};
}

Transformation TextInterfaceAscii::getTransformation(const Piece* piece)
{
	if (piece) {
		const Piece& p = *piece;
		int i=0;
		std::array<std::string, 8> ls;
		for (auto&& t : TRANSFORMATIONS) {
			std::array<char, 80> d = printPiece(p, t, i);
			for (int j=0 ; j<8 ; j++) {
				std::copy(d.begin() + 10 * j, d.begin() + 10 * (j + 1), std::back_inserter(ls[j]));
				ls[j].append(" | ");
			}
			i++;
		}

		for (int i=0 ; i<ls.size() ; i++) {
			m_os << ls[i] << "\n";
		}
		m_os << "\n";
	}


	m_os << "Choisissez une orientation ";
	int t;
	m_is >> t;
	m_os << std::endl << std::endl;
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (t >= 0 && t < TRANSFORMATIONS.size())
		return TRANSFORMATIONS[t];
	else
		return Transformation::None;
}

std::ostream& TextInterfaceAscii::getMessageOutput()
{
	return m_os;
}

void TextInterfaceAscii::clearMessages()
{
	// no-op
}

void TextInterfaceAscii::displayBoard(const Board& board)
{
	for (int line = Board::SIZE - 1 ; line >= 0 ; line--) {
		m_os << std::setw(2) << line << " ";
		for (int column = 0 ; column < Board::SIZE ; column++) {
			switch (board.getColor(Coordinate{column, line})) {
				case Color::Empty:
					//m_os << "· ";
					m_os << " . ";
					break;
				case Color::Blue:
					m_os << " # ";
					break;
				case Color::Yellow:
					m_os << " * ";
					break;
				case Color::Red:
					m_os << " $ ";
					break;
				case Color::Green:
					m_os << " % ";
					break;
			}
		}
		m_os << "\n";
	}
	m_os << "   ";
	for (int column = 0 ; column < Board::SIZE ; column++) {
		m_os << " " << (column% 10) << " ";
	}
	m_os << "\n   ";
	for (int column = 0 ; column < Board::SIZE ; column++) {
		//m_os << " " << (column % 10) << " ";
	}
	m_os << std::endl;
}
