#include <iostream>
using namespace std;

class PokerCard
{
public:
    PokerCard(std::string s, int f)
    {
        suit = s;
        face = f;
    }
    friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
    {
        out<<"["<<p.face<<" of "<<p.suit<<"]";
        return out;
    }

    //Please finish the operator override
    //請完成運算子多載
    //spade > heart > diamond > club
    //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    int _suit(string s) {
        string sSuit[4]={"club", "diamond", "heart", "spade"};
        for (int i=0; i<4; i++) {
            if (s==sSuit[i])
                return i;
        }
    }
    int _face(int n) {
        int num[13]={2, 3, 4, 5, 6, 7 ,8 , 9, 10, 11, 12, 13, 1};
        for (int i=0; i<13; i++) {
            if (n==num[i])
                return i;
        }
    }
    bool operator>(PokerCard &b)
    {
        int myFace=_face(this->face);
        int bFace=_face(b.face);
        int mySuit=_suit(this->suit);
        int bSuit=_suit(b.suit);
        if (myFace>bFace)
            return true;
        else if (myFace<bFace)
            return false;
        else {
            if (mySuit>bSuit)
                return true;
            else   
                return false;

        }
    }
    bool operator<(PokerCard &b)
    {
        int myFace=_face(this->face);
        int bFace=_face(b.face);
        int mySuit=_suit(this->suit);
        int bSuit=_suit(b.suit);
        if (myFace<bFace)
            return true;
        else if (myFace>bFace)
            return false;
        else {
            if (mySuit<bSuit)
                return true;
            else
                return false;
        }
    }
    bool operator==(PokerCard &b)
    {
        return (this->face==b.face && this->suit==b.suit);
    }

private:
    std::string suit;
    int face;
};

int main()
{
    PokerCard **card = (PokerCard **)malloc(sizeof(PokerCard *) * 52);

    std::string s[] = {"spade", "heart", "diamond", "club"};
    int j, k;
    for(j = 0;j < 4;j ++)
        for(k = 1;k <= 13;k ++)
            card[j * 13 + k - 1] = new PokerCard(s[j], k);
    for(j = 0;j < 52;j ++)
    {
        for(k = 0;k < 52;k ++)
        {
            std::cout<<*(card[j])<<">"<<*(card[k])<<":"<<(*(card[j])>*(card[k]))<<std::endl;
            std::cout<<*(card[j])<<"<"<<*(card[k])<<":"<<(*(card[j])<*(card[k]))<<std::endl;
            std::cout<<*(card[j])<<"=="<<*(card[k])<<":"<<(*(card[j])==*(card[k]))<<std::endl;
        }
    }
}
