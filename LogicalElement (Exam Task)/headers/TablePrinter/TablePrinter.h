#ifndef TABLEPRINTER_H_INCLUDED
#define TABLEPRINTER_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
using namespace std;



class TablePrinter
{

    private:

        string title;
        int lineCount;
        int colCount;
        int currentEleCount;
        int tableWidth;
        int colWidthDefault;
        int lineNumberColWidth;


        //Pseudographics characters
        char chColDiv = (char)179;
        char chLineDiv = (char)196;
        char chUpLeft = (char)218;
        char chUpMiddle = (char)194;
        char chUpRight = (char)191;
        char chDownLeft = (char)192;
        char chDownMiddle = (char)193;
        char chDownRight = (char)217;
        char chMiddleLeft = (char)195;
        char chMiddleMiddle = (char)197;
        char chMiddleRight = (char)180;

        vector<string> columnHeaders;
        vector<int> columnWidths;




	TablePrinter& printTableHeader(){
		//First of all, compute the table width
		tableWidth = accumulate(columnWidths.begin(), columnWidths.end(), tableWidth);
		tableWidth += colCount + 1;
		tableWidth += lineNumberColWidth + 1;

		int tileMargin = (tableWidth - 2 - (int)title.length())/2;
		if (tileMargin<1) tileMargin = 1;

		cout<<endl<<chUpLeft<<setfill(chLineDiv)<<setw(tableWidth-2)<<chLineDiv<<chUpRight<<endl;
		cout<<chColDiv<<setfill(' ')<<setw(tileMargin)<<""<< title <<setw(tableWidth - 1 - tileMargin - (int)title.length())<<chColDiv<<endl;
		cout<<chUpLeft<<setfill(chLineDiv);
		cout<<setw(lineNumberColWidth+1)<<chUpMiddle;
		for(int i = 0; i<colCount-1; i++)
			cout<<setw(columnWidths[i]+1)<<chUpMiddle;
		cout<<setw(columnWidths[colCount-1]+1)<<chUpRight;


		//Print column headers
		cout<<endl<<chColDiv;
        cout<<setw(lineNumberColWidth)<<""<<chColDiv;
		for(int i = 0; i<colCount; i++)
			cout<<setw(columnWidths[i])<<columnHeaders[i]<<chColDiv;


		//Print the divider below the column headers
		cout<<endl<<chMiddleLeft<<setfill(chLineDiv);
		cout<<setw(lineNumberColWidth+1)<<chMiddleMiddle;
		for(int i = 0; i<colCount-1; i++)
			cout<<setw(columnWidths[i]+1)<<chMiddleMiddle;
		cout<<setw(columnWidths[colCount-1]+1)<<chMiddleRight;
		(cout).fill(' ');

		return *this;
	}


public:

    TablePrinter(string _title, int _lineCount, int _colCount){
        title = _title;
        lineCount = _lineCount;
        colCount = _colCount;
        currentEleCount = 0;
        ostringstream stringBuilder;
        tableWidth = 0;
		lineNumberColWidth = 3;
		colWidthDefault = 5;
        for(int i=0; i< colCount; i++)
		{
			stringBuilder.str("");
			stringBuilder<<i;
			columnHeaders.push_back(stringBuilder.str());
		}
		columnWidths = vector<int>(colCount, colWidthDefault);
    }

	TablePrinter& setColumnHeader(unsigned int colIndice, string header)
	{
		columnHeaders[colIndice]=(header);
		columnWidths[colIndice]=(header.size());
		return *this;
	}


	template <typename T> TablePrinter& printValue(T ele)
	{
		if(currentEleCount == 0)
		{
			printTableHeader();
		}
		int colIndice = currentEleCount%colCount;

		if( colIndice == 0)	//New line begins
		{
			cout<<endl<<chColDiv<<setfill(' ');
            cout<<setw(lineNumberColWidth)<< currentEleCount/colCount <<chColDiv;
		}
		cout<<setfill(' ')<<setw(columnWidths[colIndice])<<ele<<chColDiv;
		currentEleCount ++;

        //Finish section
		if(currentEleCount == lineCount*colCount)
		{
			cout<<endl<<chDownLeft<<setfill(chLineDiv);
			cout<<setw(lineNumberColWidth+1)<<chDownMiddle;
			for(int i = 0; i<colCount-1; i++)
				cout<<setw(columnWidths[i]+1)<<chDownMiddle;
			cout<<setw(columnWidths[colCount-1]+1)<<chDownRight<<endl<<endl;
		}

		//Draw divider on the end of the line
		else if(currentEleCount%colCount == 0 )
		{
			cout<<endl<<chMiddleLeft<<setfill(chLineDiv);
			cout<<setw(lineNumberColWidth+1)<<chMiddleMiddle;
			for(int i = 0; i<colCount-1; i++)
				cout<<setw(columnWidths[i]+1)<<chMiddleMiddle;
			cout<<setw(columnWidths[colCount-1]+1)<<chMiddleRight;
		}
		return * this;
	}


	TablePrinter& setTitle(string _title){
	    title=_title;
        return *this;
    }

};


#endif // TABLEPRINTER_H_INCLUDED
