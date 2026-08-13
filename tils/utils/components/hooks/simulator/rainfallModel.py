def project_water_level(current_level, rainfall_mm, absorption_rate=0.3):
    """Estimate water level rise from rainfall input, minus ground absorption."""
    effective_rain = rainfall_mm * (1 - absorption_rate)
    return round(current_level + (effective_rain / 100), 2)