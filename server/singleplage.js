const puppeteer = require('puppeteer'); 

function doStuff() {

(async () => {

  const browser = await puppeteer.launch({args: ['--no-sandbox', '--disable-setuid-sandbox']});

  const page = await browser.newPage();

  await page.setUserAgent('Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36');

  await page.setViewport({width:1920, height:1080});
  await page.goto('https://my.appoptics.com/s/public/gx42sze0m?duration=21600', {waitUntil: 'networkidle2'});
  await page.screenshot({path: 'profit.png'});

  await browser.close();
})();
};

function run() {
//  setInterval(doStuff, 30000);
  setInterval(doStuff, 3000);
};

run();
