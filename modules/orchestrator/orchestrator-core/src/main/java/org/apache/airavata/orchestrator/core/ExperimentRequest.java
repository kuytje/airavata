/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
*/
package org.apache.airavata.orchestrator.core;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * This is the initial experiment Creation request
 * This is simple compair to JobRequest object in registry-api
 * This contains user specified userExperimentID
 */
public class ExperimentRequest {
    private final static Logger logger = LoggerFactory.getLogger(ExperimentRequest.class);

    private String userName;

    private String userExperimentID;
    
    private String orchestratorID;

    public String getUserExperimentID() {
        return userExperimentID;
    }

    public void setUserExperimentID(String userExperimentID) {
        this.userExperimentID = userExperimentID;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

	public String getOrchestratorID() {
		return orchestratorID;
	}

	public void setOrchestratorID(String orchestratorID) {
		this.orchestratorID = orchestratorID;
	}
}
