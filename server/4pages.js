const puppeteer = require('puppeteer'); 
(async () => {

  const browser = await puppeteer.launch({args: ['--no-sandbox', '--disable-setuid-sandbox']});

  const page = await browser.newPage();

  await page.setUserAgent('Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36');

  await page.setViewport({width:960, height:540});
  await page.goto('https://my.appoptics.com/s/public/gx42sze0m?duration=21600', {waitUntil: 'networkidle2'});
  await page.screenshot({path: 'screenshot1.png'});
  
  await page.goto('https://my.appoptics.com/s/public/xs3w5q3pc?duration=21600', {waitUntil: 'networkidle2'});
  await page.screenshot({path: 'screenshot2.png'});
  
  await page.goto('https://my.appoptics.com/s/public/luucozkwe?duration=21600', {waitUntil: 'networkidle2'});
  await page.screenshot({path: 'screenshot3.png'});

  await browser.close();
})();
