#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <vector>

class View
{
    public:
        /* CON/DECON */
        View();
        virtual ~View();

        /* GETS */
        std::string getTitle();
        std::vector<std::string> getActions();
        std::string getNote();
        bool noteActive();

        /* SETS */
        void setTitle(std::string);
        void setActions(std::vector<std::string>);
        void setNote(std::string);

        /* PRINTS */
        void printVerticalWhiteSpace(int = 20);
        void printTitle(bool = true);
        void printActions(int = 2);
        void printLineBreak(char = '-', int = 80, bool = false);
        void printAttributeBar(int, int, std::string, int = 15, char = '=', bool = true);
        void printAccountInfoBar(std::string, std::string, int, bool = true);
        void printBlockNote(std::string, char='*', int=0, int=1, int=1);
        void printMiddleOfBlockNote(std::string, char='*', int=1);

        /* METHODS */
        void pressEnterToContinue();



    protected:
    private:
        std::string title;
        std::vector<std::string> actions;
        std::string note;
        bool showNote = false;
        void printEmpty(int);

        const int linesAccross = 80;
        const int linesDown = 20;
};



#endif // VIEW_H
