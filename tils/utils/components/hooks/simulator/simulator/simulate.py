from rainfallModel import project_water_level

def run_scenarios(base_level, rainfall_list):
    return [
        {"rainfall_mm": r, "projected_level": project_water_level(base_level, r)}
        for r in rainfall_list
    ]