#include "main.h"
#include "stm32f4xx_hal.h"

SPI_HandleTypeDef hspi1;

/* Pin definitions */
#define TFT_CS_PORT GPIOB
#define TFT_CS_PIN  GPIO_PIN_6

#define TFT_DC_PORT GPIOA
#define TFT_DC_PIN  GPIO_PIN_9

#define TFT_RST_PORT GPIOC
#define TFT_RST_PIN  GPIO_PIN_7

/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);

void TFT_WriteCommand(uint8_t cmd);
void TFT_WriteData(uint8_t data);
void TFT_Reset(void);
void TFT_Init(void);
void TFT_DrawChar(char c, uint16_t x, uint16_t y);
void TFT_DrawString(char *str, uint16_t x, uint16_t y);

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_SPI1_Init();

  TFT_Init();

  TFT_DrawString("JAI BHEEM",60,120);

  while (1)
  {
  }
}

void TFT_Reset(void)
{
  HAL_GPIO_WritePin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_RESET);
  HAL_Delay(50);
  HAL_GPIO_WritePin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_SET);
  HAL_Delay(50);
}

void TFT_WriteCommand(uint8_t cmd)
{
  HAL_GPIO_WritePin(TFT_DC_PORT,TFT_DC_PIN,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(TFT_CS_PORT,TFT_CS_PIN,GPIO_PIN_RESET);

  HAL_SPI_Transmit(&hspi1,&cmd,1,100);

  HAL_GPIO_WritePin(TFT_CS_PORT,TFT_CS_PIN,GPIO_PIN_SET);
}

void TFT_WriteData(uint8_t data)
{
  HAL_GPIO_WritePin(TFT_DC_PORT,TFT_DC_PIN,GPIO_PIN_SET);
  HAL_GPIO_WritePin(TFT_CS_PORT,TFT_CS_PIN,GPIO_PIN_RESET);

  HAL_SPI_Transmit(&hspi1,&data,1,100);

  HAL_GPIO_WritePin(TFT_CS_PORT,TFT_CS_PIN,GPIO_PIN_SET);
}

void TFT_Init(void)
{
  TFT_Reset();

  TFT_WriteCommand(0x11);
  HAL_Delay(120);

  TFT_WriteCommand(0x29);
}

void TFT_DrawChar(char c,uint16_t x,uint16_t y)
{
  /* simple pixel block for demo */
  for(int i=0;i<20;i++)
  {
    for(int j=0;j<10;j++)
    {
      TFT_WriteData(0xFF);
      TFT_WriteData(0xFF);
    }
  }
}

void TFT_DrawString(char *str,uint16_t x,uint16_t y)
{
  while(*str)
  {
    TFT_DrawChar(*str,x,y);
    x+=12;
    str++;
  }
}

/* SPI INIT */

static void MX_SPI1_Init(void)
{
  hspi1.Instance=SPI1;
  hspi1.Init.Mode=SPI_MODE_MASTER;
  hspi1.Init.Direction=SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize=SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity=SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase=SPI_PHASE_1EDGE;
  hspi1.Init.NSS=SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler=SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit=SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode=SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation=SPI_CRCCALCULATION_DISABLE;

  HAL_SPI_Init(&hspi1);
}

/* GPIO INIT */

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct={0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  GPIO_InitStruct.Pin=GPIO_PIN_7;
  GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
  HAL_GPIO_Init(GPIOC,&GPIO_InitStruct);

  GPIO_InitStruct.Pin=GPIO_PIN_9;
  HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

  GPIO_InitStruct.Pin=GPIO_PIN_6;
  HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);

  GPIO_InitStruct.Pin=GPIO_PIN_5|GPIO_PIN_7;
  GPIO_InitStruct.Mode=GPIO_MODE_AF_PP;
  GPIO_InitStruct.Alternate=GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}
