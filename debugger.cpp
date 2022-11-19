

private:
    string spacer(int x)
    {
        string cc = "";
        for (int y = x - 7; y > 0; y--)
        {
            cc += " ";
        }
        return cc;
    }

    string dasher(int x)
    {
        string cc = "";
        for (int y = x - 7; y > 0; y--)
        {
            cc += "-";
        }
        return cc;
    }

public:
    void debug()
    {
        cout << endl;
        DLink<E> *temp = head;
        int index = -1;
        int tempindex = 0;
        string tb = "    .-----------";
        string tl = ".\n";
        string bb = "    '-----------";
        string bl = "'";
        string ca = "    |  ";
        string cb = "  |";
        string al = "        ^    .\n";
        string tc = "        |    |\n";
        string ac = " |    | ";
        string ar = "        '    v";
        string xx = "";
        string xy = "";
        string xz = "";
        while (temp != nullptr)
        {
            ostringstream oss;
            oss << curr;
            string s(oss.str());
            int space = (((s + " ").length()) - 1);
            xz = (curr == temp ? "  <-- CURR" : " ");
            cout << spacer(space) << tb << dasher(space) << tl << spacer(space) << ca << temp << cb + " = " << ((temp == head) ? "HEAD" : (temp == tail) ? "TAIL"
                                                                                                                                                        : ("POS " + to_string(index) + ": " + to_string(temp->theElement)))
                << xz << "\n" + spacer(space) + bb << dasher(space) << bl << endl;
            (temp != tail) ? (cout << spacer(space) << al << spacer(space) << tc << temp << ac << temp->nextPtr << "\n"
                                << spacer(space) << tc << spacer(space) << ar << endl)
                        : (cout << endl);
            if (temp == curr)
            {
                tempindex = index;
            }
            xx = ((curr == head) ? " - HEAD" : (curr == tail) ? " - TAIL"
                                                            : " - ITEM");
            xy = (curr != head && curr != tail) ? (" at POSITION ") : xy;

            temp = temp->nextPtr;
            index++;
        }

        cout << "CURRENT POINTER: " << curr;
        if (curr != head && curr != tail)
        {
            cout << xx << xy << tempindex << endl;
        }
        else
        {
            cout << xx << xy << endl;
        }
        cout << "NUMBER OF ITEMS: " << cnt << "\n\n\n\n"
            << endl;
    }