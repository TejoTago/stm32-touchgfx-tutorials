#include <gui/lollipop_screen/lollipopView.hpp>
#include <stdlib.h>
#include <math.h> //Wave

lollipopView::lollipopView()
: tickCounter(0), time(0.0f) // Wave
{
    for(int i = 0; i < 12; i++)
    {
        monthValues[i] = 5;
        wavePhase[i] = i * 0.5f; // Wave
    }
}

void lollipopView::setupScreen()
{
    lollipopViewBase::setupScreen();

    generateRandomValues();
    updateAllLollipops();
}

void lollipopView::tearDownScreen()
{
    lollipopViewBase::tearDownScreen();
}

void lollipopView::generateRandomValues()
{
    for(int i = 0; i < 12; i++)
    {
        monthValues[i] = 5 + (rand() % 181); // Valores entre 5 e 185
    }
}

void lollipopView::updateLollipop(int month, int value)
{
    // Garantir que o valor está no intervalo correto
    if(value < 5) value = 5;
    if(value > 185) value = 185;

    // As linhas começam todas em Y=185 (base) e vão até o valor
    // Os círculos devem estar posicionados no topo da linha
    int circleY = value+13; // Ajustar posição Y do círculo (centro é 20px)

    switch(month)
    {
        case 0:
            line1.setStart(30, value);
            circle1.setY(circleY);
            line1.invalidate();
            circle1.invalidate();
            break;
        case 1:
            line2.setStart(60, value);
            circle2.setY(circleY);
            line2.invalidate();
            circle2.invalidate();
            break;
        case 2:
            line3.setStart(90, value);
            circle3.setY(circleY);
            line3.invalidate();
            circle3.invalidate();
            break;
        case 3:
            line4.setStart(120, value);
            circle4.setY(circleY);
            line4.invalidate();
            circle4.invalidate();
            break;
        case 4:
            line5.setStart(150, value);
            circle5.setY(circleY);
            line5.invalidate();
            circle5.invalidate();
            break;
        case 5:
            line6.setStart(180, value);
            circle6.setY(circleY);
            line6.invalidate();
            circle6.invalidate();
            break;
        case 6:
            line7.setStart(210, value);
            circle7.setY(circleY);
            line7.invalidate();
            circle7.invalidate();
            break;
        case 7:
            line8.setStart(240, value);
            circle8.setY(circleY);
            line8.invalidate();
            circle8.invalidate();
            break;
        case 8:
            line9.setStart(270, value);
            circle9.setY(circleY);
            line9.invalidate();
            circle9.invalidate();
            break;
        case 9:
            line10.setStart(300, value);
            circle10.setY(circleY);
            line10.invalidate();
            circle10.invalidate();
            break;
        case 10:
            line11.setStart(330, value);
            circle11.setY(circleY);
            line11.invalidate();
            circle11.invalidate();
            break;
        case 11:
            line12.setStart(360, value);
            circle12.setY(circleY);
            line12.invalidate();
            circle12.invalidate();
            break;
    }
}


void lollipopView::updateAllLollipops()
{
    for(int i = 0; i < 12; i++)
    {
        updateLollipop(i, monthValues[i]);
    }
    lines.invalidate();
    circles.invalidate();
}

//void lollipopView::handleTickEvent()
//{
//    lollipopViewBase::handleTickEvent();
//
//    tickCounter++;
//
//    // 120 ticks = 2 segundos (assumindo 60 FPS)
//    if(tickCounter >= 120)
//    {
//        tickCounter = 0;
//
//        // Gerar novos valores aleatórios
//        generateRandomValues();
//
//        // Atualizar todos os lollipops
//        updateAllLollipops();
//    }
//}
void lollipopView::handleTickEvent() // Wave
{
    lollipopViewBase::handleTickEvent();

    tickCounter++;

    // 60 ticks = 1 segundo (assumindo 60 FPS)
    if(tickCounter >= 3)
    {
        tickCounter = 0;

        // Gerar valores com efeito onda
        generateWaveValues();

        updateAllLollipops();
    }
}

//void lollipopView::generateWaveValues()
//{
//    for(int i = 0; i < 12; i++)
//    {
//        // Criar onda sinusoidal com fase diferente para cada mês
//        float wave = sin(time + wavePhase[i]);
//
//        // Converter de [-1, 1] para [5, 185]
//        // Centro em 95, amplitude de 90
//        monthValues[i] = 95 + (int)(wave * 90.0f);
//    }
//
//    time += 0.1f; // Incrementar tempo para animação contínua
//}

//void lollipopView::generateWaveValues()
//{
//    for(int i = 0; i < 12; i++)
//    {
//        float wave = sin(time + wavePhase[i]);
//        wave = wave * wave * (wave > 0 ? 1.0f : -1.0f); // Onda ao quadrado
//        monthValues[i] = 95 + (int)(wave * 90.0f);
//    }
//    time += 0.15f; // Velocidade diferente
//}

//void lollipopView::generateWaveValues()
//{
//    for(int i = 0; i < 12; i++)
//    {
//        float t = fmod(time + wavePhase[i], 6.28f); // 2*PI
//        float wave = (t < 3.14f) ? (t / 1.57f - 1.0f) : (3.0f - t / 1.57f);
//        monthValues[i] = 95 + (int)(wave * 90.0f);
//    }
//    time += 0.1f;
//}

void lollipopView::generateWaveValues()
{
    for(int i = 0; i < 12; i++)
    {
        float wave = cos(time + wavePhase[i]);
        monthValues[i] = 95 + (int)(wave * 90.0f);
    }
    time += 0.1f;
}
