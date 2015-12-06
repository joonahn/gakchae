#ifndef ITEMBOX
#define ITEMBOX
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
 
enum Boxtype{
    box,
    Baquibug,
    AK_47,
    BurgerkingCoupon,
    Hanger,
    Munji,
    OneyearsAgoReport,
    Tellnumber_61





};


class ItemBox : public QObject, public QGraphicsPixmapItem
{
   public:
        ItemBox(int,int, int);
        int check;
        int type;





};


#endif // ITEMBOX

