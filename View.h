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

        /* SETS */
        void setTitle(std::string);
        void setActions(std::vector<std::string>);

        /* PRINTS */
        void printTitle(bool = true);
        void printActions();
        void printLineBreak(char = '-', int = 80, bool = false);
        void printAttributeBar(int, int, std::string, int = 15, char = '=', bool = true);

    protected:
    private:
        std::string title;
        std::vector<std::string> actions;
        void printEmpty(int);
};

#endif // VIEW_H
