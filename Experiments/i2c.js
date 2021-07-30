const i2c = require('i2c-bus');

const ADDR = 0x08;

const wbuf = Buffer.from("a")

i2c.openPromisified(1).then(i2c1 => {
  i2c1.i2cWrite(ADDR, wbuf.length, wbuf)
  .then(data => console.log(data))
  .then(_ => i2c1.close())
}).catch(console.log);