#include "game.h"
game::game()
{
    //sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;
    //settings.depthBits = 24;

    if(!backTexture.loadFromFile("Resources/back2.jpg"))
    {
        cout<<"error line 9";
    }
    background.setTexture(backTexture);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.create(sf::VideoMode::getDesktopMode(),"Moara");
    Meniu.setWidth(window.getSize().x);
    Meniu.setHeight(window.getSize().y);
    p1.setNumber(1);
    p2.setNumber(2);

}
game::~game()
{
    //dtor
}
void game::handleMousePressed()
{
    if(p1.getTurn() == true)
    {
        if(!p1.pieseDePus.empty())
            if(putPiece(p1))
            {
                p1.setTurn(false);
                p2.setTurn(true);
            }
    }
    else
    {
        if(!p2.pieseDePus.empty())
            if(putPiece(p2))
            {
                p2.setTurn(false);
                p1.setTurn(true);
            }
    }
}
bool game::putPiece(player& p)
{
    bool piecePlaced = false;
    int counterBox = 0;
    for(auto i:boxes)
    {
        if(i.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            //if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(p.pieseDePus.empty())
                break;
            if(p.getTurn() == true)
            {
                //std::cout<<"clicked ";
                //std::cout<<counterBox;
                if(pieceIsInBox[counterBox] == true)
                    break;
                p.pieseDePus[p.pieseDePus.size()-1].circle.setPosition(i.getPosition()-sf::Vector2f(10,10));
                p.piesePeTabla.push_back(make_pair(p.pieseDePus[p.pieseDePus.size()-1], false));
                p.pieseDePus.pop_back();
                pieceIsInBox[counterBox] = true;
                piecePlaced = true;
                break;
            }
        }
        counterBox++;
    }
    return piecePlaced;

}
bool game::makeCar(player& p)
{
    //nu e bine cand am la mijloc puse, acolo unde am 3 pauza 3 :  0 0 0 -- 0 0 0
    //mai multe greseli
    int iCounter = 0, jCounter = 0;
    if(p.piesePeTabla.size() > 2)
        for(auto i = p.piesePeTabla.begin(); i!=p.piesePeTabla.end()-2; ++i)
        {
            iCounter++;
            jCounter=iCounter;
            for(auto j = p.piesePeTabla.begin()+iCounter; j!=p.piesePeTabla.end()-1; ++j)
            {
                jCounter++;
                for(auto k = p.piesePeTabla.begin()+jCounter; k!=p.piesePeTabla.end(); ++k)
                {
                    sf::Vector2f aux = i->first.circle.getPosition()-j->first.circle.getPosition();
                    //tre sa separ cumva cazurile
                    if(((aux.x>-10)&&(aux.x<10))||((aux.y>-10)&&(aux.y<10)))
                    {
                        aux =i->first.circle.getPosition()-k->first.circle.getPosition();
                        if(((aux.x>-10)&&(aux.x<10))||((aux.y>-10)&&(aux.y<10)))
                        {
                            //mai am aici de lucrat
                            if((i->second == false)||(j->second == false)||(k->second == false))
                            {
                                i->second = j->second = k->second = true;
                                cout<<"car";
                                return true;
                            }
                        }
                    }

                }
            }
        }
    return false;
}
void game::iaPiesaDeLa(player& p)
{
    int counter = 0, ok = 0, boxCounter = 0;
    if(p.piesePeTabla.size()>2)
        do
        {
            counter = 0;
            for(auto i:p.piesePeTabla)
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    if(i.first.circle.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        if(i.second == false)
                        {
                            ok = 1;
                            //draw();
                            p.piesePeTabla.erase(p.piesePeTabla.begin()+counter);
                            cout<<" stearsa piesa ";
                            break;
                        }
                    }
                counter++;
            }
        }
        while(ok != 1);

}
void game::updatePieceIsInBox(player& p)
{
    int counterBox = 0;
    for(auto i:boxes)
    {
    bool ok = false;
        for(auto j:p.piesePeTabla)
        {
            if(i.getGlobalBounds().intersects(j.first.circle.getGlobalBounds()))
            {ok = true;
            break;}
        }
        pieceIsInBox[counterBox] = ok;
        counterBox++;
    }
}
void game::makeBoard()
{
    #pragma region draw lines

    for (int i = 1; i <= 3; i++)
    {
        sf::RectangleShape line(sf::Vector2f(window.getSize().x / 2 - 200 * i, 3));
        line.setPosition(sf::Vector2f(window.getSize().x / 5 + 100 * i, 100 * i));
        lines.push_back(line);

        line.setPosition(line.getPosition().x, line.getPosition().y + line.getSize().x);
        lines.push_back(line);
    }
    for (int i = 1; i <= 3; i++)
    {
        sf::RectangleShape line(sf::Vector2f(3, lines[(i - 1) * 2].getSize().x));
        line.setPosition(lines[(i - 1) * 2].getPosition().x, lines[(i - 1) * 2].getPosition().y);
        lines.push_back(line);

        line.setPosition(line.getPosition().x + line.getSize().y, line.getPosition().y);
        lines.push_back(line);
    }

    sf::RectangleShape line(sf::Vector2f(3, lines[0].getSize().x / 2 - 100));
    line.setPosition(lines[0].getPosition().x + lines[0].getSize().x / 2, lines[0].getPosition().y);
    lines.push_back(line);


    sf::RectangleShape line1(sf::Vector2f(3, lines[1].getSize().x / 2 - 100));
    line1.setPosition(lines[1].getPosition().x + lines[1].getSize().x / 2, lines[1].getPosition().y);
    line1.setScale(1, -1);
    lines.push_back(line1);


    sf::RectangleShape line2(sf::Vector2f(lines[6].getSize().y / 2 - 100, 3));
    line2.setPosition(lines[6].getPosition().x, lines[6].getPosition().y + lines[6].getSize().y / 2);
    lines.push_back(line2);


    sf::RectangleShape line3(sf::Vector2f(3, lines[7].getSize().y / 2 - 100));
    line3.setPosition(lines[7].getPosition().x,lines[7].getPosition().y + lines[7].getSize().y / 2);
    line3.rotate(90);
    lines.push_back(line3);

    #pragma endregion

    #pragma region draw boxes
        
    sf::RectangleShape box(sf::Vector2f(20, 20));
    int c = 9;
    for (int i = 0; i <= 5; i++)
    {
        box.setPosition(lines[i].getPosition().x - c, lines[i].getPosition().y - c);
        boxes.push_back(box);

        box.setPosition(lines[i].getPosition().x + lines[i].getSize().x - c, lines[i].getPosition().y - c);
        boxes.push_back(box);
    }

    box.setPosition(lines[lines.size()-1].getPosition().x - c, lines[lines.size()-1].getPosition().y - c);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 1].getPosition().x - lines[lines.size() - 1].getSize().y / 2 - c, lines[lines.size() - 1].getPosition().y - c);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 1].getPosition().x - lines[lines.size() - 1].getSize().y - c, lines[lines.size() - 1].getPosition().y - c);
    boxes.push_back(box);


    box.setPosition(lines[lines.size() - 2].getPosition().x - c, lines[lines.size() - 2].getPosition().y - c);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 2].getPosition().x + lines[lines.size() - 2].getSize().x / 2 - c, lines[lines.size() - 2].getPosition().y - c);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 2].getPosition().x + lines[lines.size() - 2].getSize().x - c, lines[lines.size() - 2].getPosition().y - c);
    boxes.push_back(box);

    box.setPosition(lines[lines.size() - 3].getPosition().x - c, lines[lines.size() - 3].getPosition().y - c+1);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 3].getPosition().x - c , lines[lines.size() - 3].getPosition().y - lines[lines.size() - 3].getSize().y / 2 - c +1);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 3].getPosition().x - c, lines[lines.size() - 3].getPosition().y - lines[lines.size() - 3].getSize().y - c+1);
    boxes.push_back(box);

    box.setPosition(lines[lines.size() - 4].getPosition().x - c, lines[lines.size() - 4].getPosition().y - c );
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 4].getPosition().x - c, lines[lines.size() - 4].getPosition().y + lines[lines.size() - 4].getSize().y / 2 - c);
    boxes.push_back(box);
    box.setPosition(lines[lines.size() - 4].getPosition().x - c, lines[lines.size() - 4].getPosition().y + lines[lines.size() - 4].getSize().y - c );
    boxes.push_back(box);



    for (auto i : boxes)
        pieceIsInBox.push_back(false);
    #pragma endregion


}

void game::run()
{
    p1.initiateWithAllPieces(window);
    p2.initiateWithAllPieces(window);
    Meniu.init();
    makeBoard();
    p1.setTurn(true);
    p2.setTurn(false);
    while(window.isOpen())
    {
        processEvents();
        update();
        draw();
    }
}
void game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::MouseButtonPressed:
            if(Meniu.getVisibility() == false)
                switch(event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    handleMousePressed();
                    if(makeCar(p1))//&&(p2.getTurn() == true))
                    {
                        iaPiesaDeLa(p2);
                        updatePieceIsInBox(p2);
                    }
                    else if(makeCar(p2))//&&(p1.getTurn() == true))
                    {
                        iaPiesaDeLa(p1);
                        updatePieceIsInBox(p1);
                    }
                    break;
                    default:
                    break;//(event.type == sf::Event::MouseButtonPressed
                }
            break;
        case sf::Event::KeyReleased:
            switch(event.key.code)
            {
            case sf::Keyboard::Escape:
                Meniu.setVisibility(true);
                break;
            case sf::Keyboard::Up:
                Meniu.moveUp();
                break;
            case sf::Keyboard::Down:
                Meniu.moveDown();
                break;
            case sf::Keyboard::Return:
                if(Meniu.getVisibility() == true)
                    switch(Meniu.elementulSelectat)
                    {
                    case 0:
                        //play
                        Meniu.setVisibility(false);
                        break;
                    case 1:
                        //options
                        break;
                    case 2:
                        //close
                        window.close();
                        break;
                    }
            }
        }
    }
}
void game::update()
{

}

void game::draw()
{
    window.clear();
    //background
    window.draw(background);

//afisam tabla de joc
    for(auto i:lines)
        window.draw(i);
// spatiile unde poti pune piese
    for(auto i:boxes)
        window.draw(i);

//meniu
    if(Meniu.getVisibility() == true)
        Meniu.drawMainMenu(window);

//afisare piesele
    p1.drawPieces(window);
    p2.drawPieces(window);

    window.display();
}

