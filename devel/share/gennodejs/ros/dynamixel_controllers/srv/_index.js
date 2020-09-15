
"use strict";

let RestartController = require('./RestartController.js')
let TorqueEnable = require('./TorqueEnable.js')
let SetTorqueLimit = require('./SetTorqueLimit.js')
let StopController = require('./StopController.js')
let SetComplianceSlope = require('./SetComplianceSlope.js')
let SetCompliancePunch = require('./SetCompliancePunch.js')
let StartController = require('./StartController.js')
let SetSpeed = require('./SetSpeed.js')
let SetComplianceMargin = require('./SetComplianceMargin.js')

module.exports = {
  RestartController: RestartController,
  TorqueEnable: TorqueEnable,
  SetTorqueLimit: SetTorqueLimit,
  StopController: StopController,
  SetComplianceSlope: SetComplianceSlope,
  SetCompliancePunch: SetCompliancePunch,
  StartController: StartController,
  SetSpeed: SetSpeed,
  SetComplianceMargin: SetComplianceMargin,
};
