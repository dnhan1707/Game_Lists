//
// Created by ASUS on 12/9/2023.
//

#include "PokerAnalysis.h"

PokerAnalysis::PokerAnalysis() {

//    std::vector<std::vector<Card>> cardSets;
    cardSets.push_back({
                               Card(ACE, HEART),
                               Card(TEN, HEART),
                               Card(JACK, HEART),
                               Card(QUEEN, HEART),
                               Card(KING, HEART)
                       });
    cardSets.push_back({
                               Card(FOUR, HEART),
                               Card(FIVE, HEART),
                               Card(SIX, HEART),
                               Card(SEVEN, HEART),
                               Card(EIGHT, HEART)
                       });
    cardSets.push_back({
                               Card(FOUR, HEART),
                               Card(FOUR, SPADES),
                               Card(FOUR, CLUBS),
                               Card(FOUR, DIAMOND),
                               Card(EIGHT, HEART)
                       });
    cardSets.push_back({
                               Card(EIGHT, HEART),
                               Card(EIGHT, SPADES),
                               Card(EIGHT, DIAMOND),
                               Card(KING, DIAMOND),
                               Card(KING, HEART)
                       });
    cardSets.push_back({
                               Card(TEN, SPADES),
                               Card(FOUR, HEART),
                               Card(TEN, SPADES),
                               Card(JACK, SPADES),
                               Card(QUEEN, HEART)
                       });
    cardSets.push_back({
                               Card(SEVEN, HEART),
                               Card(EIGHT, SPADES),
                               Card(NINE, DIAMOND),
                               Card(TEN, HEART),
                               Card(JACK, CLUBS)
                       });
    cardSets.push_back({
                               Card(EIGHT, HEART),
                               Card(EIGHT, SPADES),
                               Card(EIGHT, DIAMOND),
                               Card(QUEEN, HEART),
                               Card(KING, HEART)
                       });
    cardSets.push_back({
                               Card(EIGHT, HEART),
                               Card(EIGHT, SPADES),
                               Card(TEN, HEART),
                               Card(TEN, SPADES),
                               Card(KING, HEART)
                       });
    cardSets.push_back({
                               Card(TEN, HEART),
                               Card(TEN, SPADES),
                               Card(JACK, HEART),
                               Card(QUEEN, HEART),
                               Card(KING, HEART)
                       });
    cardSets.push_back({
                               Card(TWO, HEART),
                               Card(FIVE, SPADES),
                               Card(SIX, CLUBS),
                               Card(QUEEN, DIAMOND),
                               Card(KING, HEART)
                       });
    while (!ScoreHand::isRoyalFlush()) {
        Deck deck;
        deck.shuffle();
        CardHand cardHand;

        cardHand.giveCardsToPlayer(deck);

        CardHandScorer cardHandScorer(cardHand);

        cardHandScorer.calculateNumDup();
        cardHandScorer.calculateUnique();

        cardHandScorer.identifyHand();

    }
}

void PokerAnalysis::run()
{

}

void PokerAnalysis::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    int royal_flush_score       = ScoreHand::getScore(ROYAL_FLUSH);
    int straight_flush_score    = ScoreHand::getScore(STRAIGHT_FLUSH);
    int four_of_a_kind_score    = ScoreHand::getScore(FOUR_OF_A_KIND);
    int full_house_score        = ScoreHand::getScore(FULL_HOUSE);
    int flush_score             = ScoreHand::getScore(FLUSH);
    int straight_score          = ScoreHand::getScore(STRAIGHT);
    int three_of_a_kind_score   = ScoreHand::getScore(THREE_OF_A_KIND);
    int two_plate_score         = ScoreHand::getScore(TWO_PAIR);
    int one_pair_score          = ScoreHand::getScore(ONE_PAIR);
    int high_hand_score         = ScoreHand::getScore(HIGH_CARD);

    std::string royal_ratio_str             = std::to_string(high_hand_score) + " : 1";
    std::string straight_flush_ratio_str    = std::to_string(one_pair_score) + " : 1";
    std::string four_of_ratio_str           = std::to_string(two_plate_score) + " : 1";
    std::string full_house_ratio_str        = std::to_string(three_of_a_kind_score) + " : 1";
    std::string flush_ratio_str             = std::to_string(straight_score)  + " : 1";
    std::string straight_ratio_str          = std::to_string(flush_score)  + " : 1";
    std::string three_ratio_str             = std::to_string(full_house_score)  + " : 1";
    std::string two_ratio_str               = std::to_string(four_of_a_kind_score)  + " : 1";
    std::string one_pair_str                = std::to_string(straight_flush_score)  + " : 1";
    std::string one_ratio_str               = std::to_string(royal_flush_score) + " : 1";

    LetterBox letterBox1(royal_ratio_str, {500, 50});
    LetterBox letterBox2(straight_flush_ratio_str, {500, 150});
    LetterBox letterBox3(four_of_ratio_str, {500, 250});
    LetterBox letterBox4(full_house_ratio_str, {500, 350});
    LetterBox letterBox5(flush_ratio_str, {500, 450});
    LetterBox letterBox6(straight_ratio_str, {500, 550});
    LetterBox letterBox7(three_ratio_str, {500, 650});
    LetterBox letterBox8(two_ratio_str, {500, 750});
    LetterBox letterBox9(one_pair_str, {500, 850});
    LetterBox letterBox10(one_ratio_str, {500, 950});


    sf::Vector2f position(0, 50);
    for (const std::vector<Card>& cardSet : cardSets)
    {
        for (const Card& card : cardSet)
        {
            CardGraphic cardGraphic(card, position);
            window.draw(cardGraphic);
            position.x += cardSpacing;
        }
        position.y += 100;
        position.x = 0;
    }
    window.draw(letterBox1);
    window.draw(letterBox2);
    window.draw(letterBox3);
    window.draw(letterBox4);
    window.draw(letterBox5);
    window.draw(letterBox6);
    window.draw(letterBox7);
    window.draw(letterBox8);
    window.draw(letterBox9);
    window.draw(letterBox10);

}

void PokerAnalysis::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void PokerAnalysis::update()
{

}

std::string PokerAnalysis::getName() {
    return "Poker Analysis";
}
