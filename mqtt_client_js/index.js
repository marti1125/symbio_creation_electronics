var mqtt = require('mqtt')
var client  = mqtt.connect('mqtt://192.168.1.136')

client.on('connect', function () {
  client.subscribe('sensor/basura', function (err) {
    if (!err) {
      client.publish('sensor/basura', 'Hello mqtt')
    }
  })
})

client.on('message', function (topic, message) {
  // message is Buffer
  console.log(message.toString())
  client.end()
})
